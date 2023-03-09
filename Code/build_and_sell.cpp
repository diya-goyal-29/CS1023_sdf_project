#include <iostream>
#include <SFML/Graphics.hpp>
#include "players.h"
#include <array>
#include <string>
#include<vector>
#include"start.h"
#include"build_and_sell.h"
#include"properties.h"
#include"BoardCode.h"

void selection(sell_or_buy type,player pl,pair_t& p,int sz,sf::RenderWindow &window, std::array<sf::RectangleShape, 40> &rect1, std::array<sf::RectangleShape, 5> &rect2,sf::RectangleShape& confirm_r,bool &prop_sel,bool &num_sel)
{
	
	for (int i = 0; i < 40; i++)
	{
		if (rect1[i].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
		{
			prop_sel=true;

			rect1[i].setOutlineColor(sf::Color(255, 0, 0));
			rect1[i].setOutlineThickness(3);
			for (int j = 0; j < sz; j++)
			{
				if (j != i)
				{
					rect1[j].setOutlineColor(sf::Color(255, 255, 255));
				}
			}
			p.p=i;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		if (rect2[i].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
		{
			if(prop_sel==false)
			{
				msgDisplay("First select a property");
			}
			else
			{
			if(type==sell_or_buy::BUY && pl.playerHouses[p.p]+(i+1)>5)
			{
				msgDisplay("No. of houses cannot exceed 5");
			}
			else if(type==sell_or_buy::SELL && pl.playerHouses[p.p]<(i+1))
			{
				msgDisplay("You can't sell more than you have");
			}
			else
			{
				num_sel=true;
				rect2[i].setOutlineColor(sf::Color(255, 0, 0));
				rect2[i].setOutlineThickness(3);
				for (int j = 0; j < 5; j++)
				{
					if (j != i)
					{
						rect2[j].setOutlineColor(sf::Color(255, 255, 255));
					}
				}
				p.n=(i+1);
			}
			}
		}
	}
}

std::array<std::string, 5> numbers = {"1", "2", "3", "4", "5"};

void build(player pl[],int index, sf::RenderWindow &main_window,sf::Vector2f Coods[],int size)
{
	int sz = pl[index].numbProps ;
	sf::Font font;
	

	if (!font.loadFromFile("../Fonts/Champagne & Limousines.ttf"))
	{
		std::cout << "Loading Error" << std::endl;
	}

	


	std::array<sf::Text, 2> heading;
	for (int i = 0; i < 2; i++)
	{
		heading[i].setFont(font);
		heading[i].setPosition(70 + 500 * i, 40);
		heading[i].setFillColor(sf::Color(255, 255, 0));
	}
	heading[0].setString("PROPERTIES");
	heading[1].setString("NUMBER_OF_HOUSES");

	std::array<sf::RectangleShape, 40> rect1;
	std::array<sf::RectangleShape, 5> rect2;
	std::array<sf::Text, 40> text1;
	std::array<sf::Text, 5> text2;
	int num=0;
	for(int i=0;i<pl[index].numbProps;i++)
	{
		int find = Find_group(pl[index].playerProps[i]);

		if (pl[index].count[find] == pl[index].max_count[find])
		{ 
			rect1[i].setSize(sf::Vector2f(300, 60));
			rect1[i].setPosition(50, 100 + num * 100);
			rect1[i].setOutlineThickness(3);
			rect1[i].setOutlineColor(sf::Color::White);
			rect1[i].setFillColor(sf::Color(0, 0, 0));
			text1[i].setFont(font);
			text1[i].setString(places[pl[index].playerProps[i]]);
			text1[i].setPosition(70, 110 + num * 100);
			text1[i].setStyle(sf::Text::Bold);
			num++;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		rect2[i].setSize(sf::Vector2f(100, 50));
		rect2[i].setPosition(650, 100 + i * 100);
		rect2[i].setOutlineThickness(3);
		rect2[i].setOutlineColor(sf::Color::White);
		rect2[i].setFillColor(sf::Color(0, 0, 0));
		text2[i].setFont(font);
		text2[i].setString(numbers[i]);
		text2[i].setPosition(670, 110 + i * 100);
	}


	sf::RectangleShape confirm_r(sf::Vector2f(250,60));
	confirm_r.setPosition(100, 650 );
	confirm_r.setOutlineThickness(3);
	confirm_r.setOutlineColor(sf::Color::White);
	confirm_r.setFillColor(sf::Color(0, 0, 0));
	confirm_r.setFillColor(sf::Color(255,10,100));

	sf::Text confirm_t;
	confirm_t.setFont(font);
	confirm_t.setString("CONFIRM");
	confirm_t.setPosition(120, 660);
	confirm_t.setStyle(sf::Text::Bold);

	sf::RectangleShape cancel_r(sf::Vector2f(250,60));
	cancel_r.setPosition(570, 650 );
	cancel_r.setOutlineThickness(3);
	cancel_r.setOutlineColor(sf::Color::White);
	cancel_r.setFillColor(sf::Color(0, 0, 0));
	cancel_r.setFillColor(sf::Color(255,10,100));

	sf::Text cancel_t;
	cancel_t.setFont(font);
	cancel_t.setString("CANCEL");
	cancel_t.setPosition(590, 660);
	cancel_t.setStyle(sf::Text::Bold);

	pair_t pr;
	pr.p=0;
	pr.n=0;
	if(num>0)
	{
		sf::RenderWindow window(sf::VideoMode(900, 850), "Build");
		window.clear();
		
		bool prop_sel=false;
		bool num_sel=false;
		while (window.isOpen()) 
		{	
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				
				selection(sell_or_buy::BUY,pl[index],pr,sz,window, rect1, rect2,confirm_r,prop_sel,num_sel);
				if (confirm_r.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
				{
					if(prop_sel==false || num_sel==false)
					{
						msgDisplay("Select both property and no. of houses");
					}
					else
						window.close();
					
				}
				if (cancel_r.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
				{
					pr.p=0;
					pr.n=0;
					window.close();
					
				}
			}

			window.draw(heading[0]);
			window.draw(heading[1]);
			for (int i = 0; i < 40; i++)
			{
				window.draw(rect1[i]);
				window.draw(text1[i]);
			}
			for (int i = 0; i < 5; i++)
			{
				window.draw(rect2[i]);
				window.draw(text2[i]);
			}
			window.draw(confirm_r);
			window.draw(confirm_t);
			window.draw(cancel_r);
			window.draw(cancel_t);

			window.display();
		}
		
		
	}
	else
	{
		pr.n=0;
		pr.p=0;
		msgDisplay("You didn't have a monopoly yet");
	}
	if(pr.n>0)
	{
		int j=pr.n==5 ? 1 :0;
		pl[index].money -= ((pr.n)*(house_cost[pl[index].playerProps[pr.p]][j]));
		pl[index].playerHouses[pr.p] += pr.n;
		houses[pr.p]+=pr.n;
		pl[index].playerValue += pr.n*house_cost[pl[index].playerProps[pr.p]][j];
		disp_house(pl[index].playerProps[pr.p],pl[index].playerHouses[pr.p],Coods,main_window,size,pl);
	}
	
}

void sell(player pl[],int index, sf::RenderWindow &main_window,sf::Vector2f Coods[],int size)
{
	int sz = pl[index].numbProps ;
	sf::Font font;

	if (!font.loadFromFile("../Fonts/Champagne & Limousines.ttf"))
	{
		std::cout << "Loading Error" << std::endl;
	}
	std::array<sf::Text, 2> heading;
	for (int i = 0; i < 2; i++)
	{
		heading[i].setFont(font);
		heading[i].setPosition(70 + 500 * i, 40);
		heading[i].setFillColor(sf::Color(255, 255, 0));
	}
	heading[0].setString("PROPERTIES");
	heading[1].setString("NUMBER_OF_HOUSES");

	std::array<sf::RectangleShape, 40> rect1;
	std::array<sf::RectangleShape, 5> rect2;
	std::array<sf::Text, 40> text1;
	std::array<sf::Text, 5> text2;
	int num=0;
	for (int i = 0; i < sz; i++)
	{
		if(pl[index].playerHouses[i]>0)
		{
			rect1[i].setSize(sf::Vector2f(300, 60));
			rect1[i].setPosition(50, 100 + num * 100);
			rect1[i].setOutlineThickness(3);
			rect1[i].setOutlineColor(sf::Color::White);
			rect1[i].setFillColor(sf::Color(0, 0, 0));
			text1[i].setFont(font);
			text1[i].setString(places[pl[index].playerProps[i]]);
			text1[i].setPosition(70, 110 + num * 100);
			text1[i].setStyle(sf::Text::Bold);
			num++;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		rect2[i].setSize(sf::Vector2f(100, 50));
		rect2[i].setPosition(650, 100 + i * 100);
		rect2[i].setOutlineThickness(3);
		rect2[i].setOutlineColor(sf::Color::White);
		rect2[i].setFillColor(sf::Color(0, 0, 0));
		text2[i].setFont(font);
		text2[i].setString(numbers[i]);
		text2[i].setPosition(670, 110 + i * 100);
	}


	sf::RectangleShape confirm_r(sf::Vector2f(250,60));
	confirm_r.setPosition(100, 650 );
	confirm_r.setOutlineThickness(3);
	confirm_r.setOutlineColor(sf::Color::White);
	confirm_r.setFillColor(sf::Color(0, 0, 0));
	confirm_r.setFillColor(sf::Color(255,10,100));

	sf::Text confirm_t;
	confirm_t.setFont(font);
	confirm_t.setString("CONFIRM");
	confirm_t.setPosition(120, 660);
	confirm_t.setStyle(sf::Text::Bold);

	sf::RectangleShape cancel_r(sf::Vector2f(250,60));
	cancel_r.setPosition(570, 650 );
	cancel_r.setOutlineThickness(3);
	cancel_r.setOutlineColor(sf::Color::White);
	cancel_r.setFillColor(sf::Color(0, 0, 0));
	cancel_r.setFillColor(sf::Color(255,10,100));

	sf::Text cancel_t;
	cancel_t.setFont(font);
	cancel_t.setString("CANCEL");
	cancel_t.setPosition(590, 660);
	cancel_t.setStyle(sf::Text::Bold);

	pair_t pr;
	pr.p=0;
	pr.n=0;
	
	if(num>0)
	{
		sf::RenderWindow window(sf::VideoMode(900, 850), "Sell");
		window.clear();
		bool prop_sel=false;
		bool num_sel=false;
		while (window.isOpen()) 
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				selection(sell_or_buy::SELL,pl[index],pr,sz,window, rect1, rect2,confirm_r,prop_sel,num_sel);
				if (confirm_r.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
				{
					if(prop_sel==false || num_sel==false)
					{
						msgDisplay("Select both property and no. of houses");
					}
					else
						window.close();
					
				}
				if (cancel_r.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
				{
					pr.p=0;
					pr.n=0;
					window.close();
					
				}
			}

			window.draw(heading[0]);
			window.draw(heading[1]);
			for (int i = 0; i < sz; i++)
			{
				window.draw(rect1[i]);
				window.draw(text1[i]);
			}
			for (int i = 0; i < 5; i++)
			{
				window.draw(rect2[i]);
				window.draw(text2[i]);
			}
			window.draw(confirm_r);
			window.draw(confirm_t);
			window.draw(cancel_r);
			window.draw(cancel_t);

			window.display();
		}
	}
	else
	{
		pr.n=0;
		pr.p=0;
		msgDisplay("You didn't have any houses yet");
	}
	int j = pr.n==5 ? 1 :0;
	pl[index].money += ((pr.n)*(house_cost[pl[index].playerProps[pr.p]][j]));	
	pl[index].playerHouses[pr.p] -= pr.n;
	houses[pr.p]-=pr.n;
	pl[index].playerValue -= pr.n*house_cost[pl[index].playerProps[pr.p]][j];
	disp_house(pl[index].playerProps[pr.p],pl[index].playerHouses[pr.p],Coods,main_window,size,pl);
	   
	
	
}

