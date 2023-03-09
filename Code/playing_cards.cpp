#include <iostream>
#include<SFML/Graphics.hpp>
#include"playing_cards.h"
#include"properties.h"

void playing_cards(int num,player& pl,int i,bool& plbuy)
{
	sf::RenderWindow window_p(sf::VideoMode(800, 600), "Play Card");
	sf::Font font;
	if (!font.loadFromFile("../Fonts/Champagne & Limousines.ttf"))
	{
		std::cout << "Loading Error" << std::endl;
	}

	sf::Text text1;
	text1.setFont(font);
	text1.setFillColor(sf::Color::Black);
	text1.setStyle(sf::Text::Bold | sf::Text::Underlined);

	sf::Text text2;
	text2.setFont(font);
	text2.setPosition(330, 120);
	text2.setFillColor(sf::Color::Black);
	text2.setStyle(sf::Text::Bold | sf::Text::Underlined);

	sf::Text text3;
	text3.setFont(font);
	text3.setPosition(220, 170);
	text3.setFillColor(sf::Color::Black);

	sf::RectangleShape rect1(sf::Vector2f(400.f, 70.f));
	rect1.setPosition(200, 10);
	rect1.setOutlineThickness(5);
	rect1.setOutlineColor(sf::Color::White);

	sf::RectangleShape rect2(sf::Vector2f(400.f, 500.f));
	rect2.setPosition(200, 80);
	rect2.setOutlineThickness(5);
	rect2.setOutlineColor(sf::Color::White);
	
	sf::RectangleShape rect3(sf::Vector2f(100, 50));
	rect3.setPosition(50, 300);
	rect3.setOutlineThickness(5);
	rect3.setOutlineColor(sf::Color::White);
	rect3.setFillColor(sf::Color(255, 10, 100));

	sf::RectangleShape rect4(sf::Vector2f(100, 50));
	rect4.setPosition(650, 300);
	rect4.setOutlineThickness(5);
	rect4.setOutlineColor(sf::Color::White);
	rect4.setFillColor(sf::Color(255,10,100));

	sf::Text text4;
	text4.setFont(font);
	text4.setString("BUY");
	text4.setPosition(70, 305);
	text4.setStyle(sf::Text::Bold);

	sf::Text text5;
	text5.setFont(font);
	text5.setString("LEAVE");
	text5.setPosition(660, 305);
	text5.setStyle(sf::Text::Bold);
	
	sf::Sprite sprite;
	sf::Texture texture;

    switch(num) {
        case 1:
        	text1.setString("Guwahati");
		text1.setPosition(340, 90);
        	text2.setString("Cost : $60");
	    	text3.setString("Rent without House : $6\nRent with 1 House : $20\nRent with 2 House : $40\nRent with 3 House : $90\nRent with 4 House : $160\nRent with Hotel : $250\n\nMortage Value : $40\nCost of House : $40\nCost of Hotel : $70\n");
        	rect1.setFillColor(sf::Color(135, 211, 124));
        	break;
        case 3:
		text1.setString("Bhuwaneshwar");
		text1.setPosition(310, 90);
		text2.setString("Cost : $80");
        	text3.setString("Rent without House : $8\nRent with 1 House : $20\nRent with 2 House : $60\nRent with 3 House : $180\nRent with 4 House : $320\nRent with Hotel : $450\n\nMortage Value : $40\nCost of House : $40\nCost of Hotel : $70\n");
		rect1.setFillColor(sf::Color(135, 211, 124));
		break;
        case 5:
	{
		text1.setString("Chennai Central");
		text1.setPosition(310, 20);
		text2.setString("Cost : $200");
		text2.setPosition(330, 60);
		if (!texture.loadFromFile("../Images/Railroad.jpg")) {
		std::cout << "Loading Error" << std::endl;
		}
		sprite.setTexture(texture);
		sprite.setPosition(sf::Vector2f(300.f, 100.f));
		text3.setString("Rent : $25\nRent with 2 Railways : $50\nRent with 3 Railways : $100\nRent with 4 Railways : $200\n\nMortage Value : $100\n");
		text3.setPosition(220, 300);
		rect1.setFillColor(sf::Color::White);
        	break;
	}
        case 6:
		text1.setString("Panaji");
		text1.setPosition(360, 90);
		text2.setString("Cost : $100");
		text3.setString("Rent without House : 10\nRent with 1 House : $30\nRent with 2 House : $90\nRent with 3 House : $270\nRent with 4 House : $400\nRent with Hotel : $550\n\nMortage Value : $50\nCost of House : $50\nCost of Hotel : $50\n");
		rect1.setFillColor(sf::Color(27, 163, 157));
        	break;
        case 7:
		text1.setString("Agra");
		text1.setPosition(370, 90);
		text2.setString("Cost : $100");
		text3.setString("Rent without House : $10\nRent with 1 House : $30\nRent with 2 House : $90\nRent with 3 House : $270\nRent with 4 House : $400\nRent with Hotel : $550\n\nMortage Value : $50\nCost of House : $50\nCost of Hotel : $80\n");
		rect1.setFillColor(sf::Color(27, 163, 157));
        	break;
        case 9:
		text1.setString("Vadodara");
		text1.setPosition(340, 90);
		text2.setString("Cost : $100");
		text3.setString("Rent without House : $10\nRent with 1 House : $30\nRent with 2 House : $90\nRent with 3 House : $270\nRent with 4 House : $400\nRent with Hotel : $550\n\nMortage Value : $50\nCost of House : $50\nCost of Hotel : $80\n");
		rect1.setFillColor(sf::Color(27, 163, 157));
        	break;
        case 11:
		text1.setString("Ludhiana");
		text1.setPosition(350, 90);
		text2.setString("Cost : $140");
		text3.setString("Rent without House : $14\nRent with 1 House : $50\nRent with 2 House : $150\nRent with 3 House : $450\nRent with 4 House : $625\nRent with Hotel : $750\n\nMortage Value : $70\nCost of House : $100\nCost of Hotel : $150\n");
		rect1.setFillColor(sf::Color::Red);
        	break;
        case 12:
	 {
		text1.setString("Electric Company");
		text1.setPosition(330, 20);
		text2.setString("Cost : $150");
		text2.setPosition(330, 60);
		if (!texture.loadFromFile("../Images/electric-company.png")) {
			std::cout << "Loading Error" << std::endl;
		}
		sprite.setTexture(texture);
		sprite.setPosition(sf::Vector2f(330.f, 140.f));
		text3.setString("If one utility is owned the rent is 4\ntimes the number on die.\nIf both the utilities are owned the \nrent is 10 times the number on die.\n\nMortage value : $75");
		text3.setPosition(220, 350);
		rect1.setFillColor(sf::Color::White);
		break;
	 }
        case 13:
		text1.setString("Patna");
		text1.setPosition(350, 90);
		text2.setString("Cost : $140");
		text3.setString("Rent without House : $14\nRent with 1 House : $50\nRent with 2 House : $150\nRent with 3 House : $450\nRent with 4 House : $625\nRent with Hotel : $750\n\nMortage Value : $70\nCost of House : $100\nCost of Hotel : $150\n");
		rect1.setFillColor(sf::Color::Red);
        	break;
        case 14:
		text1.setString("Bhopal");
		text1.setPosition(350, 90);
        	text2.setString("Cost : $160");
		text3.setString("Rent without House : $16\nRent with 1 House : $60\nRent with 2 House : $250\nRent with 3 House : $500\nRent with 4 House : $700\nRent with Hotel : $900\n\nMortage Value : $80\nCost of House : $150\nCost of Hotel : $200\n");
		rect1.setFillColor(sf::Color::Red);
		break;
        case 15:
	{
		text1.setString("Howrah Station");
		text1.setPosition(310, 20);
		text2.setString("Cost : $200");
		text2.setPosition(330, 60);
		if (!texture.loadFromFile("../Images/Railroad.jpg")) {
			std::cout << "Loading Error" << std::endl;
		}
		sprite.setTexture(texture);
		sprite.setPosition(sf::Vector2f(300.f, 100.f));
		text3.setString("Rent : $25\nRent with 2 Railways : $50\nRent with 3 Railways : $100\nRent with 4 Railways : $200\n\nMortage Value : $100\n");
		text3.setPosition(220, 300);
		rect1.setFillColor(sf::Color::White);
		break;
	}
        case 16:
		text1.setString("Indore");
		text1.setPosition(350, 90);
        	text2.setString("Cost : $150");
		text3.setString("Rent without House : $15\nRent with 1 House : $70\nRent with 2 House : $200\nRent with 3 House : $550\nRent with 4 House : $750\nRent with Hotel : $950\n\nMortage Value : $75\nCost of House : $175\nCost of Hotel : $250\n");
		rect1.setFillColor(sf::Color::Magenta);
		break;
        case 18:
		text1.setString("Nagpur");
		text1.setPosition(350, 90);
        	text2.setString("Cost : $160");
		text3.setString("Rent without House : $16\nRent with 1 House : $70\nRent with 2 House : $200\nRent with 3 House : $550\nRent with 4 House : $750\nRent with Hotel : $950\n\nMortage Value : $80\nCost of House : $175\nCost of Hotel : $250\n");
		rect1.setFillColor(sf::Color::Magenta);
		break;
        case 19:
		text1.setString("Kochi");
		text1.setPosition(350, 90);
        	text2.setString("Cost : $200");
		text3.setString("Rent without House : $20\nRent with 1 House : $80\nRent with 2 House : $220\nRent with 3 House : $600\nRent with 4 House : $800\nRent with Hotel : $1000\n\nMortage Value : $100\nCost of House : $200\nCost of Hotel : $275\n");
		rect1.setFillColor(sf::Color::Magenta);
		break;
        case 21:
		text1.setString("Lucknow");
		text1.setPosition(350, 90);
        	text2.setString("Cost : $220");
		text3.setString("Rent without House : $22\nRent with 1 House : $90\nRent with 2 House : $250\nRent with 3 House : $700\nRent with 4 House : $825\nRent with Hotel : $1050\n\nMortage Value : $110\nCost of House : $200\nCost of Hotel : $350\n");
		rect1.setFillColor(sf::Color(253, 227, 167));
		break;
        case 23:
		text1.setString("Chandigarh");
		text1.setPosition(330, 90);
		text2.setString("Cost : $220");
		text3.setString("Rent without House : $22\nRent with 1 House : $90\nRent with 2 House : $250\nRent with 3 House : $700\nRent with 4 House : $875\nRent with Hotel : $1050\n\nMortage Value : $110\nCost of House : $200\nCost of Hotel : $350\n");
		rect1.setFillColor(sf::Color(253, 227, 167));
        	break;
        case 24:
		text1.setString("Jaipur");
		text1.setPosition(350, 90);
        	text2.setString("Cost : $240");
		text3.setString("Rent without House : $24\nRent with 1 House : $100\nRent with 2 House : $300\nRent with 3 House : $750\nRent with 4 House : $925\nRent with Hotel : $1100\n\nMortage Value : $120\nCost of House : $250\nCost of Hotel : $450\n");
		rect1.setFillColor(sf::Color(253, 227, 167));
		break;
        case 25:
	{
		text1.setString("New Delhi Railways");
		text1.setPosition(300, 20);
        	text2.setString("Cost : $200");
		text2.setPosition(330, 60);
		if (!texture.loadFromFile("../Images/Railroad.jpg")) {
			std::cout << "Loading Error" << std::endl;
		}
		sprite.setTexture(texture);
		sprite.setPosition(sf::Vector2f(300.f, 100.f));
		text3.setString("Rent : $25\nRent with 2 Railways : $50\nRent with 3 Railways : $100\nRent with 4 Railways : $200\n\nMortage Value : $100\n");
		text3.setPosition(220, 300);
		rect1.setFillColor(sf::Color::White);
		break;
	}
        case 26:
		text1.setString("Pune");
		text1.setPosition(370, 90);
       	 	text2.setString("Cost : $220");
		text3.setString("Rent without House : $22\nRent with 1 House : $110\nRent with 2 House : $330\nRent with 3 House : $800\nRent with 4 House : $975\nRent with Hotel : $1150\n\nMortage Value : $110\nCost of House : $350\nCost of Hotel : $500\n");
		rect1.setFillColor(sf::Color(255, 203, 5));
		break;
        case 27:
	{
		text1.setString("Waterworks");
		text1.setPosition(330, 20);
		text2.setString("Cost : $150");
		text2.setPosition(330, 60);
		if (!texture.loadFromFile("../Images/waterworks.jpg")) {
			std::cout << "Loading Error" << std::endl;
		}
		sprite.setTexture(texture);
		sprite.setPosition(sf::Vector2f(270.f, 100.f));
		text3.setString("If one utility is owned the rent is 4\ntimes the number on die.\nIf both the utilities are owned the \nrent is 10 times the number on die.\n\nMortage value : $75");
		text3.setPosition(220, 350);
		rect1.setFillColor(sf::Color::White);
        	break;
	}
        case 28:
		text1.setString("Hyderabad");
		text1.setPosition(335, 90);
		text2.setString("Cost : $325");
		text3.setString("Rent without House : 32\nRent with 1 House : $120\nRent with 2 House : $360\nRent with 3 House : $850\nRent with 4 House : $1025\nRent with Hotel : $1200\n\nMortage Value : $160\nCost of House : $325\nCost of Hotel : $450\n");
		rect1.setFillColor(sf::Color(255, 203, 5));
        	break;
        case 29:
		text1.setString("Ahemdabad");
		text1.setPosition(335, 90);
		text2.setString("Cost : $280");
		text3.setString("Rent without House : $28\nRent with 1 House : $110\nRent with 2 House : $330\nRent with 3 House : $800\nRent with 4 House : $975\nRent with Hotel : $1150\n\nMortage Value : $140\nCost of House : $300\nCost of Hotel : $450\n");
		rect1.setFillColor(sf::Color(255, 203, 5));
        	break;
	case 31:
		text1.setString("Kolkata");
		text1.setPosition(350, 90);
		text2.setString("Cost : $320");
		text3.setString("Rent without House : $32\nRent with 1 House : $130\nRent with 2 House : $390\nRent with 3 House : $900\nRent with 4 House : $1100\nRent with Hotel : $1275\n\nMortage Value : $160\nCost of House : $350\nCost of Hotel : $500\n");
		rect1.setFillColor(sf::Color::Green);
        	break;
        case 32:
        	text1.setString("Chennai");
		text1.setPosition(350, 90);
		text2.setString("Cost : $320");
		text3.setString("Rent without House : 32\nRent with 1 House : $130\nRent with 2 House : $390\nRent with 3 House : $900\nRent with 4 House : $1100\nRent with Hotel : $1275\n\nMortage Value : $160\nCost of House : $350\nCost of Hotel : $500\n");
		rect1.setFillColor(sf::Color::Green);
		break;
        case 34:
		text1.setString("Banglore");
		text1.setPosition(350, 90);
		text2.setString("Cost : $330");
		text3.setString("Rent without House : $33\nRent with 1 House : $150\nRent with 2 House : $450\nRent with 3 House : $1000\nRent with 4 House : $1200\nRent with Hotel : $1400\n\nMortage Value : $165\nCost of House : $375\nCost of Hotel : $525\n");
		rect1.setFillColor(sf::Color::Green);
        	break;
        case 35:
	{
		text1.setString("Mumbai Railways");
		text1.setPosition(310, 20);
		text2.setString("Cost : $200");
		text2.setPosition(330, 60);
		if (!texture.loadFromFile("../Images/Railroad.jpg")) {
			std::cout << "Loading Error" << std::endl;
		}
		sprite.setTexture(texture);
		sprite.setPosition(sf::Vector2f(300.f, 100.f));
		text3.setString("Rent : $25\nRent with 2 Railways : $50\nRent with 3 Railways : $100\nRent with 4 Railways : $200\n\nMortage Value : $100\n");
		text3.setPosition(220, 300);
        	break;
	}
        case 37:
		text1.setString("Delhi");
		text1.setPosition(335, 90);
		text2.setString("Cost : $325");
		text3.setString("Rent without House : 32\nRent with 1 House : $175\nRent with 2 House : $500\nRent with 3 House : $1100\nRent with 4 House : $1300\nRent with Hotel : $1500\n\nMortage Value : $160\nCost of House : $400\nCost of Hotel : $550\n");
		rect1.setFillColor(sf::Color::Blue);
        	break;
        case 39:
		text1.setString("Mumbai");
		text1.setPosition(335, 90);
		text2.setString("Cost : $350");
		text3.setString("Rent without House : 35\nRent with 1 House : $200\nRent with 2 House : $600\nRent with 3 House : $1400\nRent with 4 House : $1700\nRent with Hotel : $2000\n\nMortage Value : $175\nCost of House : $400\nCost of Hotel : $550\n");
		rect1.setFillColor(sf::Color::Blue);
        	break;
    }


	while (window_p.isOpen()) {

		sf::Event event;
		while (window_p.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {

				window_p.close();
			}
			
			
			if (event.type == sf::Event::MouseButtonPressed) 
			{
				if (rect3.getGlobalBounds().contains(sf::Mouse::getPosition(window_p).x, sf::Mouse::getPosition(window_p).y))
				{
					window_p.close();
					
					owners[num] = (i + 1);
					pl.playerProps[pl.numbProps] = num;
					pl.playerHouses[pl.numbProps] = 0;
					pl.numbProps++;
					pl.count[Find_group(num)]++;
					pl.money-=prop_cost[num];
					pl.playerValue += prop_cost[num];
					plbuy = true;
				
				}
				if(rect4.getGlobalBounds().contains(sf::Mouse::getPosition(window_p).x, sf::Mouse::getPosition(window_p).y))
				{
						window_p.close();
				}
			}

		}
		
		window_p.clear();

		window_p.draw(rect1);
		window_p.draw(rect2);
		window_p.draw(text1);
		window_p.draw(text2);
		window_p.draw(text3);
		window_p.draw(rect3);
		window_p.draw(rect4);
		window_p.draw(text4);
		window_p.draw(text5);
		if(num == 5 || num == 12 || num == 15 || num == 25 || num == 27 || num == 35) {
			window_p.draw(sprite);
		}
		window_p.display();
		
		
	}
}
