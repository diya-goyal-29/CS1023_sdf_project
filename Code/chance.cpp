#include <iostream>
#include<SFML/Graphics.hpp>
#include"chance.h"

void chance_card(int dice_roll)
{
	sf::RenderWindow window_c(sf::VideoMode(800, 600), "Chance");
	sf::Font font;
	if (!font.loadFromFile("../Fonts/Champagne & Limousines.ttf"))
	{
		std::cout << "Loading Error" << std::endl;
	}

	sf::Text text1;
	text1.setFont(font);
	text1.setString("Chance");
	text1.setPosition(340, 20);
	text1.setFillColor(sf::Color::Black);
	text1.setCharacterSize(44);
	text1.setStyle(sf::Text::Bold | sf::Text::Underlined);

	sf::Texture texture;
	if (!texture.loadFromFile("../Images/chance.png")) {
		std::cout << "Loading Error" << std::endl;
	}
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(350.f, 100.f));
	sprite.setScale(0.45, 0.45);


	sf::Text text2;
	text2.setFont(font);
	
	text2.setPosition(220, 350);
	text2.setFillColor(sf::Color::Black);
	text2.setStyle(sf::Text::Bold);

	sf::RectangleShape rect2(sf::Vector2f(400.f, 570.f));
	rect2.setPosition(200, 10);
	rect2.setOutlineThickness(5);
	rect2.setOutlineColor(sf::Color::White);

    switch(dice_roll){
		case 2:
		text2.setString("\n\n\t\tAdvance to Mumbai.");
		break;
		case 3:
		text2.setString("\n\n\t\tAdvance to Go.\n\t\t(Collect $200).");
		break;
		case 4:
		text2.setString("\n\nAdvance to Jaipur.");
		break;
		case 5:
		text2.setString("Pay your health insurance $35.");
		break;
		case 6:
		text2.setString("\n\nBank pays you dividend of $50");
		break;
		case 7:
		text2.setString("You won the beauty contest.\n\t\tGet $20.");
		break;
		case 8:
		text2.setString("\n\n It is your lucky day. \n\t\tCollect $50.");
		break;
		case 9:
		text2.setString("\n\nGo to Jail. Go directly to Jail, do\n not pass Go, do not\n collect $200.");
		break;
		case 10:
		text2.setString("\n\n\t\tSpeeding fine $15.");
		break;
		case 11:
		text2.setString("\n\nMove to Mumbai.");
		break;
		case 12:
		text2.setString("\n\nYour building loan matures. \nCollect $150.");
		break;


	}

	

	while (window_c.isOpen()) {

		sf::Event event;
		while (window_c.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {

				window_c.close();
			}

		}
		window_c.clear();

		window_c.draw(rect2);
		window_c.draw(text1);
		window_c.draw(sprite);
		window_c.draw(text2);
		window_c.display();
		
	}
}
