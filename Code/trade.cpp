#include<iostream>
#include <SFML/Graphics.hpp>
#include"trade.h"

void removeIcon(int iter, sf::Vector2f boughtCoods[], sf::RenderWindow& board_win, int size, player pl[]) {
	board_win.clear();
	make_board(board_win, pl, size);
}

using namespace std;

void trade(player pl[], int player_chance, int size,sf::Vector2f boughtCoods[], sf::RenderWindow& board_win)
{

	sf::RenderWindow window1(sf::VideoMode(800, 600), "Trade");
	window1.clear();
	window1.setFramerateLimit(60);

	sf::Font font;
	if (!font.loadFromFile("../Fonts/Avara.otf"))
	{
		std::cout << "Loading Failed" << std::endl;
	}
	sf::Text text[size];

	// sf::Text text1;
	for(int i=0;i<size;i++)
	{
		if(i!=player_chance)
		{

		text[i].setFont(font);
		text[i].setCharacterSize(30);
		text[i].setFillColor(sf::Color::White);
		text[i].setStyle(sf::Text::Bold);
		text[i].setString(pl[i].playerName);
		}
	}

	sf::RectangleShape rectangle1(sf::Vector2f(150.f, 50.f));
	rectangle1.setOutlineThickness(5.f);
	rectangle1.setOutlineColor(sf::Color::White);
	rectangle1.setFillColor(sf::Color::Red);

	sf::Text text5;
	text5.setFont(font);
	text5.setString("confirm");
	text5.setCharacterSize(30);
	text5.setFillColor(sf::Color::White);
	text5.setStyle(sf::Text::Bold);
	
	int selected_player; 

	int money1 = 0;
	int money2 = 0;
	int id1 = 0;
	int id2 = 0;

	while (window1.isOpen())
	{
		sf::Event event1;
		while (window1.pollEvent(event1))
		{

			if (event1.type == sf::Event::Closed)
				window1.close();
			if (event1.type == sf::Event::MouseButtonPressed)
			{
				for(int i=0;i<size;i++)
				{
					if(text[i].getGlobalBounds().contains(sf::Mouse::getPosition(window1).x, sf::Mouse::getPosition(window1).y))
					{
						text[i].setOutlineColor(sf::Color(255, 0, 0));
						text[i].setOutlineThickness(14);
						selected_player = i;
						for(int j=0;j<size;j++)
						{
							if(j!=i)
							{
								text[j].setOutlineColor(sf::Color(0, 0, 0));
							}
						}

					}
				}
			}
		}

		if (event1.type == sf::Event::MouseButtonPressed)
		{
			if (rectangle1.getGlobalBounds().contains(sf::Mouse::getPosition(window1).x, sf::Mouse::getPosition(window1).y))
			{
				window1.close();
				sf::RenderWindow window2(sf::VideoMode(1000, 800), "Players");

				sf::RectangleShape rectangle4(sf::Vector2f(150.f, 70.f));
				rectangle4.setOutlineThickness(5.f);
				rectangle4.setOutlineColor(sf::Color::White);
				rectangle4.setFillColor(sf::Color::Red);

				sf::Text text9;
				text9.setFont(font);
				text9.setCharacterSize(30);
				text9.setFillColor(sf::Color::White);
				text9.setStyle(sf::Text::Bold);

				sf::RectangleShape rectangle5(sf::Vector2f(130.f, 50.f));
				rectangle5.setOutlineThickness(5.f);
				rectangle5.setOutlineColor(sf::Color::White);
				rectangle5.setFillColor(sf::Color::Red);

				sf::Text text11;
				text11.setFont(font);
				text11.setString("Agree");
				text11.setCharacterSize(30);
				text11.setFillColor(sf::Color::White);
				text11.setStyle(sf::Text::Bold);

				sf::RectangleShape rectangle6(sf::Vector2f(150.f, 50.f));
				rectangle6.setOutlineThickness(5.f);
				rectangle6.setOutlineColor(sf::Color::White);
				rectangle6.setFillColor(sf::Color::Red);

				sf::Text text12;
				text12.setFont(font);
				text12.setString("Disagree");
				text12.setCharacterSize(30);
				text12.setFillColor(sf::Color::White);
				text12.setStyle(sf::Text::Bold);

				float length_1 = 20, width_1 = 70;
				sf::Text text_m1[40];
				for (int i = 0; i < pl[selected_player].numbProps; i++)
				{
					text_m1[i].setFont(font);
					print_places(&(pl[selected_player].playerProps[i]), text_m1[i]);
					text_m1[i].setPosition(length_1, width_1);
					width_1 += 30;
					if (width_1 == 520) {
						length_1 = 410;
						width_1 = 70;
						text_m1[i].setPosition(length_1, width_1);
					}
				}


				std::string str1;
				sf::Text name1;
				sf::Text text10;
				sf::Text text13;

				sf::RectangleShape box1(sf::Vector2f(200, 50));
				setText(text10, &font, "Enter\namount  : ", 20, 600, 30, sf::Color(0, 255, 0));
				setBox(box1, 200, 600, sf::Color(0, 0, 0), sf::Color(0, 255, 0), 2);

				setText(text13, &font, "$.  ", 205, 605, 30, sf::Color(0, 255, 0));


				std::string str2;
				sf::Text name2;
				sf::Text text14;

				sf::RectangleShape box2(sf::Vector2f(200, 50));
				setText(text14, &font, "Enter\nproperty id  : ", 500, 600, 30, sf::Color(0, 255, 0));
				setBox(box2, 700, 600, sf::Color(0, 0, 0), sf::Color(0, 255, 0), 2);


				while (window2.isOpen())
				{
					sf::Event event2;

					bool sel;

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
					{
						sel = true;
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					{
						sel = false;
					}

					while (window2.pollEvent(event2))
					{
						
						if (event2.type == sf::Event::Closed)
						{
							window2.close();
						}
						if (event2.type == sf::Event::MouseButtonPressed)
						{
							if (rectangle4.getGlobalBounds().contains(sf::Mouse::getPosition(window2).x, sf::Mouse::getPosition(window2).y))
							{
								window2.close();
							}
						}
						if (event2.type == sf::Event::TextEntered)
						{
							//#################### Taking input name from user ############

							input(window2, event2, box1, str1, name1, &font, 235, 605, sel);
							input(window2, event2, box2, str2, name2, &font, 705, 605, sel);
							
						}
						money1 = set_id(name1);
						id1 = set_id(name2);
					}
					window2.clear();
					window2.draw(box1);
					window2.draw(text10);
					window2.draw(box2);
					window2.draw(text14);
					window2.draw(text13);
					window2.draw(name1);
					window2.draw(name2);
					rectangle4.setPosition(50.0f, 700.f);
					window2.draw(rectangle4);
					text9.setString("Next");
					text9.setPosition(54.f, 715.f);
					window2.draw(text9);

					for (int i = 0; i < pl[selected_player].numbProps; i++)
					{
						window2.draw(text_m1[i]);
					}
					window2.display();

				}

				sf::RenderWindow window3(sf::VideoMode(1000, 800), "PlayersPr");

				float length = 20, width = 70;
				sf::Text text_m2[40];
				for (int j = 0; j < pl[player_chance].numbProps; j++) {
					text_m2[j].setFont(font);
					print_places(&pl[player_chance].playerProps[j], text_m2[j]);
					text_m2[j].setPosition(length, width);
					width += 30;
					if (width == 520) {
						length = 410;
						width = 70;
						text_m2[j].setPosition(length, width);
					}
				}

				std::string str3;
				sf::Text name3;

				std::string str4;
				sf::Text name4;

				while (window3.isOpen())
				{
					sf::Event event3;

					bool sel;

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
					{
						sel = true;
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					{
						sel = false;
					}

					while (window3.pollEvent(event3))
					{
						if (event3.type == sf::Event::Closed)
						{
							window3.close();
						}
						if (event3.type == sf::Event::TextEntered)
						{
							//#################### Taking input name from user ############

							input(window3, event3, box1, str3, name3, &font, 235, 605, sel);
							input(window3, event3, box2, str4, name4, &font, 705, 605, sel);
						}
						money2 = set_id(name3);
						id2 = set_id(name4);

						if (event3.type == sf::Event::MouseButtonPressed)
						{
							if (rectangle4.getGlobalBounds().contains(sf::Mouse::getPosition(window3).x, sf::Mouse::getPosition(window3).y))
							{
								sf::RenderWindow window4(sf::VideoMode(900, 600), "Property");

								sf::Text name5;
								  sf::Text name6;
								  name5.setFont(font);
								  name5.setString(pl[player_chance].playerName);
								  name5.setPosition(50.f,30.f);
								  name6.setString(pl[selected_player].playerName);
								  name6.setFont(font);
								  name6.setPosition(500.f,30.f);
								  sf::Text text15;
								  text15.setFont(font);
								  print_places(&id2, text15);
								  text15.setPosition(50.f,110.f);
								  sf::Text text16;
								  text16.setFont(font);
								  print_places(&id1, text16);
								  text16.setPosition(500.f,110.f);
								  sf::Text text17;
								  text17.setFont(font);
								  text17.setString(str3);
								  text17.setPosition(50.f,70.f);
								  sf::Text text18;
								  text18.setFont(font);
								  text18.setString(str1);
								  text18.setPosition(500.f,70.f);
								


								while (window4.isOpen())
								{
									sf::Event event4;
									while (window4.pollEvent(event4))
									{
										if (event4.type == sf::Event::Closed)
										{
											window4.close();
										}
										if (event4.type == sf::Event::MouseButtonPressed)
										{
											if (rectangle5.getGlobalBounds().contains(sf::Mouse::getPosition(window4).x, sf::Mouse::getPosition(window4).y))
											{
												window3.close();
												pl[selected_player].money+=(money2-money1);
												  pl[player_chance].money+=(money1-money2);
												  for(int i=0; i<40; i++)
												  {
													 if(pl[selected_player].playerProps[i]==id1 && id2!=0)
													 {
														 
														
														pl[selected_player].playerProps[i]=id2;
														owners[id2]=(selected_player+1);
														dispBoughtIcon(id2,selected_player,boughtCoods,board_win,size,pl);
														
													 }
													 if(pl[selected_player].playerProps[i]==id1 && id2==0)
													 {
														pl[selected_player].playerProps[i]=0;
														owners[id1]=0;
														removeIcon(id1, boughtCoods, board_win, size, pl);
													 }

													 if(pl[player_chance].playerProps[i]==id2 && id1!=0)
													 {
														pl[player_chance].playerProps[i]=id1;
														owners[id1]=(player_chance+1);
														dispBoughtIcon(id1,player_chance,boughtCoods,board_win,size,pl);
													 }
													 if(pl[player_chance].playerProps[i]==id2 && id1==0)
													 {
														pl[player_chance].playerProps[i]=0;
														owners[id2]=0;
														removeIcon(id2, boughtCoods, board_win, size, pl);
													 }
												  }
												
												window4.close();
											}
											if (rectangle6.getGlobalBounds().contains(sf::Mouse::getPosition(window4).x, sf::Mouse::getPosition(window4).y))
											{
												window4.close();
												window3.close();
											}
										}
										
									}
									window4.clear();
									rectangle5.setPosition(50.0f, 500.f);
									window4.draw(rectangle5);
									text11.setPosition(55.f, 505.f);
									window4.draw(text11);
									rectangle6.setPosition(700.0f, 500.f);
									window4.draw(rectangle6);
									text12.setPosition(703.f, 505.f);
									window4.draw(text12);
									window4.draw(name5);
									window4.draw(name6);
									window4.draw(text15);
									window4.draw(text16);
									window4.draw(text17);
									window4.draw(text18);
									window4.display();
								}
							}
						}
					}
					window3.clear();
					window3.draw(box1);
					window3.draw(text10);
					window3.draw(box2);
					window3.draw(text14);
					window3.draw(text13);
					window3.draw(name3);
					window3.draw(name4);
					rectangle4.setPosition(50.0f, 700.f);
					window3.draw(rectangle4);
					text9.setString("Confirm");
					text9.setPosition(54.f, 715.f);
					window3.draw(text9);

					for (int j = 0; j < pl[player_chance].numbProps; j++)
					{
						window3.draw(text_m2[j]);
					}
					window3.display();

				}

				window1.close();
			}
		}
		int num=0;
		for(int i=0;i<size;i++)
		{
			if(i!=player_chance)
			{
				
			text[i].setPosition(20.f,50.f*(num+1));
			window1.draw(text[i]);
			num++;
			}
		}

		rectangle1.setPosition(600.0f, 500.f);
		window1.draw(rectangle1);
		text5.setPosition(605.f, 505.f);
		window1.draw(text5);
		window1.display();
	}

}
