
#include <iostream>
#include<SFML/Graphics.hpp>
#include"community_chest.h"

void community_chest(int rand_num)
{
	sf::RenderWindow window_cc(sf::VideoMode(800, 600), "Community Chest");
	sf::Font font;
	if (!font.loadFromFile("../Fonts/Champagne & Limousines.ttf"))
	{
		std::cout << "Loading Error" << std::endl;
	}

	sf::Text text1;
	text1.setFont(font);
	text1.setString("Community Chest");
	text1.setPosition(250, 20);
	text1.setFillColor(sf::Color::Black);
	text1.setCharacterSize(44);
	text1.setStyle(sf::Text::Bold | sf::Text::Underlined);

	sf::Texture texture;
	if (!texture.loadFromFile("../Images/community-chest.jpg")) {
		std::cout << "Loading Error" << std::endl;
	}
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(300.f, 140.f));
	sprite.setScale(0.3, 0.3);


	sf::Text text2;
	text2.setFont(font);
	text2.setPosition(220, 350);
	text2.setFillColor(sf::Color::Black);
	text2.setStyle(sf::Text::Bold);

	sf::RectangleShape rect2(sf::Vector2f(400.f, 570.f));
	rect2.setPosition(200, 10);
	rect2.setOutlineThickness(5);
	rect2.setOutlineColor(sf::Color::White);

    switch (rand_num)
    {
    case 0:
    text2.setString("\n\n\t\t\tAdvance to Go \n\t\t\t(Collect $200).");
    break;
    case 1:
    text2.setString("\n\n\tBank error in your favour.\n\t\t Collect $200");
    break;
    case 2:
    text2.setString("\n\n\t\tDoctors fee. Pay $50.");
    break;
    case 3:
    text2.setString("\n\n\t\tFrom sale of stock \n\t\t\tyou get $50.");
    break;
    case 4:
    text2.setString("\n\nGo to Jail. Go directly to jail, \ndo not pass Go, \ndo not collect $200.");
    break;
    case 5:
    text2.setString("\n\n\t\tHoliday fund matures. \n\t\t\tReceive $100.");
    break;
    case 6:
    text2.setString("\n\n\t\tIncome tax refund. \n\t\t\tCollect $20.");
    break;
    case 7:
    text2.setString("\n\n\t\tLife insurance matures.\n\t\t\tCollect $100.");
    break;
    case 8:
    text2.setString("\n\n\tPay hospital fees of $100.");
    break;
    case 9:
    text2.setString("\n\n\tPay school fees of $50.");
    break;
    case 10:
    text2.setString("\n\nReceive $25 consultancy fee.");
    break;
    case 11:
    text2.setString("\n\nYou have won second prize \n\t\tin a beauty contest. \n\t\t\tCollect $10.");
    break; 
    case 12:
    text2.setString("\n\n\t\t\tYou inherit $100");
    break; 
    case 13:
    text2.setString("\n\n\tAcussed of robbery. Pay $100.");
    break;  
    }
	

	while (window_cc.isOpen()) {

		sf::Event event;
		while (window_cc.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {

				window_cc.close();
			}

		}
		window_cc.clear();

		window_cc.draw(rect2);
		window_cc.draw(text1);
		window_cc.draw(sprite);
		window_cc.draw(text2);
        window_cc.display();
		
	}
}