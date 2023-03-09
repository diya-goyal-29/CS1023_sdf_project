#include<iostream>
#include"jail.h"
#include"diceRoller.h"

roll_die jail(player pl[], int *player_chance, int *size) {
	sf::RenderWindow window_j(sf::VideoMode(600, 300), "JAIL");

	sf::Font font;
	if (!font.loadFromFile("../Fonts/Champagne & Limousines.ttf"))
	{
		std::cout << "Loading Error" << std::endl;
	}

	sf::RectangleShape rect_1(sf::Vector2f(200, 100));
	rect_1.setFillColor(sf::Color(255, 10, 100));
	rect_1.setOutlineColor(sf::Color::White);
	rect_1.setOutlineThickness(5);
	rect_1.setPosition(50, 150);

	sf::RectangleShape rect_2(sf::Vector2f(200, 100));
	rect_2.setFillColor(sf::Color(255, 10, 100));
	rect_2.setOutlineColor(sf::Color::White);
	rect_2.setOutlineThickness(5);
	rect_2.setPosition(350, 150);

	sf::Text text[3];

	text[0].setFont(font);
	text[0].setString("JAIL");
	text[0].setStyle(sf::Text::Bold | sf::Text::Underlined);
	text[0].setFillColor(sf::Color::White);
	text[0].setPosition(290, 50);

	text[1].setFont(font);
	text[1].setString("Roll Double");
	text[1].setStyle(sf::Text::Bold);
	text[1].setFillColor(sf::Color::White);
	text[1].setPosition(80, 170);

	text[2].setFont(font);
	text[2].setString("PAY $500");
	text[2].setStyle(sf::Text::Bold);
	text[2].setFillColor(sf::Color::White);
	text[2].setPosition(390, 170);

	roll_die roll;
	while (window_j.isOpen()) {
		sf::Event event;
		while (window_j.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {

				window_j.close();
			}
			if (event.type == sf::Event::MouseButtonPressed) {

				if (rect_1.getGlobalBounds().contains(sf::Mouse::getPosition(window_j).x, sf::Mouse::getPosition(window_j).y)) {
					if (pl[*player_chance].in_jail > 0) {
					
						roll = rollDice();
						if (roll.dice_1 == roll.dice_2){
							pl[*player_chance].is_jail = false;
							window_j.close();
							pl[*player_chance].get_out_of_jail=true;
							
						}
						else {
							sf::RenderWindow window(sf::VideoMode(300, 100), "Cannot play");
							sf::Text text1;
							text1.setFont(font);
							text1.setString("DID NOT GET A DOUBLE");
							text1.setFillColor(sf::Color::White);
							while (window.isOpen()) {
								sf::Event event1;
								while (window.pollEvent(event1)) {

									if (event1.type == sf::Event::Closed) {

										window.close();
									}
								}
								window.clear();
								window.draw(text1);
								window.display();
								window_j.close();
								

							}
							pl[*player_chance].in_jail--;
							if (*player_chance == (*size - 1))
            							  *player_chance = 0;
         					   	else
              							  (*player_chance)++;
							return roll;
						}
					}
						if (pl[*player_chance].in_jail <= 0) {
							sf::RenderWindow window1(sf::VideoMode(400, 100), "Chances over");
							sf::Text text2;
							text2.setFont(font);
							text2.setString("3 CHANCES ARE OVER. PAY $500");
							text2.setFillColor(sf::Color::White);
							while (window1.isOpen()) {
								sf::Event event1;
								while (window1.pollEvent(event1)) {

									if (event1.type == sf::Event::Closed) {

										window1.close();
									}
								}
								window1.clear();
								window1.draw(text2);
								window1.display();

							}
						}
					
					
				}

				if (rect_2.getGlobalBounds().contains(sf::Mouse::getPosition(window_j).x, sf::Mouse::getPosition(window_j).y)) {
					
					pl[*player_chance].money -= 500;
					pl[*player_chance].is_jail = false;
					pl[*player_chance].get_out_of_jail=true;
					window_j.close();
					
				}


			}

		}

		window_j.clear();
		window_j.draw(rect_1);
		window_j.draw(rect_2);
		for (int i = 0; i < 3; i++) {
			window_j.draw(text[i]);
		}
		window_j.display();
	}
	return roll;
	
}
