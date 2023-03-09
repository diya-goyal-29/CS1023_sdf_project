#include <iostream>
#include<sstream>
#include<string>
#include<SFML/Graphics.hpp>
#include"mortgage_or_unmortgage.h"


void print_places(int *num, sf::Text &text) {

	switch (*num) {

	case 1:
		text.setString("1 \t\t\t Guwahati");
		break;
	case 3:
		text.setString("3 \t\t\t Bhuwaneshwar");
		break;
	case 5:
		text.setString("5 \t\t Chennai Central");
		break;
	case 6:
		text.setString("6 \t\t\t Panaji");
		break;
	case 7:
		text.setString("7 \t\t\t Agra");
		break;
	case 9:
		text.setString("9 \t\t\t Vadodra");
		break;
	case 11:
		text.setString("11 \t\t\t Ludhiana");
		break;
	case 12:
		text.setString("12 \t\t Electric Company");
		break;
	case 13:
		text.setString("13 \t\t\t Patna");
		break;
	case 14:
		text.setString("14 \t\t\t Bhopal");
		break;
	case 15:
		text.setString("15 \t\t Howrah Station");
		break;
	case 16:
		text.setString("16 \t\t\t Indore");
		break;
	case 18:
		text.setString("18 \t\t\t Nagpur");
		break;
	case 19:
		text.setString("19 \t\t\t Kochi");
		break;
	case 21:
		text.setString("21 \t\t\t Lucknow");
		break;
	case 23:
		text.setString("23 \t\t\t Chandigarh");
		break;
	case 24:
		text.setString("24 \t\t\t Jaipur");
		break;
	case 25:
		text.setString("25 \t\t New Delhi Railways");
		break;
	case 26:
		text.setString("26 \t\t\t Pune");
		break;
	case 27:
		text.setString("27 \t\t\t Waterworks");
		break;
	case 28:
		text.setString("28 \t\t\t Hyderabad");
		break;
	case 29:
		text.setString("29 \t\t\t Ahemdabad");
		break;
	case 31:
		text.setString("31 \t\t\t Kolkata");
		break;
	case 32:
		text.setString("32 \t\t\t Chennai");
		break;
	case 34:
		text.setString("34 \t\t\t Banglore");
		break;
	case 35:
		text.setString("35 \t\t Mumbai Railways");
		break;
	case 37:
		text.setString("37 \t\t\t Delhi");
		break;
	case 39:
		text.setString("39 \t\t\t Mumbai");
		break;


	}

}

int set_id(sf::Text &playerInput) {
	std::stringstream ss(playerInput.getString().toAnsiString());
	int id;
	ss >> id;
	return id;
}

bool check_id(int id, player pl, bool is_fun_mort) {
	bool check = false;
	if (is_fun_mort) {
		for (int i = 0; i < 40; i++) {
			if (id == pl.playerProps[i]) {
				check = true;
			}
		}
	}
	else {
		for (int i = 0; i < 40; i++) {
			if (id == pl.playerMortProps[i]) {
				check = true;
			}
		}
	}
	return check;
}

void change_status(int *id) {
	*id = *id * (-1);
}


int mortgage_values[40] = { 0,40,0,40,0,100,50,50,0,100,0,70,75,70,80,100,75,0,80,100,0,110,0,110,120,100,110,75,160,140,0,160,160,0,165,100,0,160,0,175 };
sf::Vector2f coods[40];
sf::Vector2f boughtCoods[40];

void mortgage(player pl[], int player_chance, sf::RenderWindow& board_win, int size) {

	sf::RenderWindow window_m(sf::VideoMode(800, 600), "Mortgage");
	sf::Font font;
	if (!font.loadFromFile("../Fonts/Champagne & Limousines.ttf"))
	{
		std::cout << "Loading Error" << std::endl;
	}

	sf::Text text_m1;
	text_m1.setPosition(390, 30);
	text_m1.setFont(font);
	text_m1.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text_m1.setString(pl[player_chance].playerName);

	float length = 20, width = 70;
	sf::Text text_m2[40];
	for (int j = 0; j < pl[player_chance].numbProps; j++) {
		text_m2[j].setFont(font);
		bool should_print = true;
		for (int i = 0; i < 40; i++) {
			if (pl[player_chance].playerProps[j] == pl[player_chance].playerMortProps[i]) {
				should_print = false;
			}
		}
		if(should_print) {
			print_places(&pl[player_chance].playerProps[j], text_m2[j]);
			text_m2[j].setPosition(length, width);
			width += 30;
			if (width == 520) {
				length = 410;
				width = 70;
				text_m2[j].setPosition(length, width);
			}
		}

	}

	setCoods(coods);
	setBoughtCoods(coods, boughtCoods);

	sf::Text text_m3;
	text_m3.setPosition(100, 550);
	text_m3.setFont(font);
	text_m3.setString("Enter the property id : ");

	sf::RectangleShape background(sf::Vector2f(800, 600));
	if (player_chance == 0) {
		background.setFillColor(sf::Color(30, 130, 76));
	}
	else if (player_chance == 1) {
		background.setFillColor(sf::Color(37, 116, 169));
	}
	else if (player_chance == 2) {
		background.setFillColor(sf::Color(140, 20, 252));
	}
	else if (player_chance == 3) {
		background.setFillColor(sf::Color(211, 84, 0));
	}


	sf::RectangleShape box(sf::Vector2f(100, 30));
	box.setPosition(430, 550);
	box.setOutlineThickness(5);
	box.setOutlineColor(sf::Color::Red);
	box.setFillColor(sf::Color::Red);

	std::string playerInput;
	sf::Text playerText;
	playerText.setFont(font);
	playerText.setFillColor(sf::Color::White);
	playerText.setPosition(430, 550);
	
	sf::Text text[40];
	for (int i = 0; i < 40; i++) {
		text[i].setFont(font);
	}

	while (window_m.isOpen()) {
		sf::Event event;

		while (window_m.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {

				window_m.close();
			}

			if (event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode == '\b' && playerInput != "\0")
					playerInput.erase(playerInput.size() - 1, sizeof(char32_t));

				else
					playerInput += static_cast<char>(event.text.unicode);

			}
			playerText.setString(playerInput);

			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Enter) {

					int id = set_id(playerText);
					bool check = check_id(id, pl[player_chance], true);
					if (check) {
						
						pl[player_chance].money += mortgage_values[id];
						pl[player_chance].playerMortProps[id] = id;
						change_status(&owners[id]);
						pl[player_chance].numbMortProps += 1;
						dispMortgageIcon(id, player_chance, boughtCoods, board_win, size, pl);
						pl[player_chance].playerValue -= prop_cost[id];
						window_m.close();
					}
					else {
						sf::RenderWindow window1(sf::VideoMode(500, 100), "Error message");
						sf::Text text;
						text.setFont(font);
						text.setString("Please enter correct id.");
						text.setFillColor(sf::Color::White);
						text.setPosition(100, 30);
						while (window1.isOpen()) {
							sf::Event event1;
							while (window1.pollEvent(event1)) {

								if (event1.type == sf::Event::Closed) {

									window1.close();
								}
							}
							window1.clear();
							window1.draw(text);
							window1.display();
							window_m.close();
						}
					}
				}
			}
		}


		window_m.clear();
		window_m.draw(background);
		window_m.draw(text_m1);
		for (int j = 0; j < pl[player_chance].numbProps; j++) {
			window_m.draw(text_m2[j]);
		}
		window_m.draw(text_m3);
		window_m.draw(box);
		window_m.draw(playerText);
		window_m.display();
	}

}

void unmortgage(player pl[], int player_chance, sf::RenderWindow& board_win, int size) {

	sf::RenderWindow window_um(sf::VideoMode(800, 600), "Unmortgage");
	sf::Font font;
	if (!font.loadFromFile("../Fonts/Champagne & Limousines.ttf"))
	{
		std::cout << "Loading Error" << std::endl;
	}

	sf::Text text_um1;
	text_um1.setPosition(390, 30);
	text_um1.setFont(font);
	text_um1.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text_um1.setString(pl[player_chance].playerName);

	float length = 20, width = 70;
	sf::Text text_um2[40];
	for (int j = 0; j < 40; j++) {
		if (pl[player_chance].playerMortProps[j] == 0) {
			continue;
		}
		else {
			text_um2[j].setFont(font);
			print_places(&pl[player_chance].playerMortProps[j], text_um2[j]);
			text_um2[j].setPosition(length, width);
			width += 30;
			if (width == 520) {
				length = 410;
				width = 70;
				text_um2[j].setPosition(length, width);
			}
		}

	}

	setCoods(coods);
	setBoughtCoods(coods, boughtCoods);

	sf::Text text_um3;
	text_um3.setPosition(100, 550);
	text_um3.setFont(font);
	text_um3.setString("Enter the property id : ");

	sf::RectangleShape background(sf::Vector2f(800, 600));
	if (player_chance == 0) {
		background.setFillColor(sf::Color(30, 130, 76));
	}
	else if (player_chance == 1) {
		background.setFillColor(sf::Color(37, 116, 169));
	}
	else if (player_chance == 2) {
		background.setFillColor(sf::Color(140, 20, 252));
	}
	else if (player_chance == 3) {
		background.setFillColor(sf::Color(211, 84, 0));
	}


	sf::RectangleShape box(sf::Vector2f(100, 30));
	box.setPosition(430, 550);
	box.setOutlineThickness(5);
	box.setOutlineColor(sf::Color::Red);
	box.setFillColor(sf::Color::Red);

	std::string playerInput;
	sf::Text playerText;
	playerText.setFont(font);
	playerText.setFillColor(sf::Color::White);
	playerText.setPosition(430, 550);

	while (window_um.isOpen()) {
		sf::Event event;

		while (window_um.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {

				window_um.close();
			}

			if (event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode == '\b' && playerInput != "\0")
					playerInput.erase(playerInput.size() - 1, sizeof(char32_t));

				else
					playerInput += static_cast<char>(event.text.unicode);
			}
			playerText.setString(playerInput);

			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Enter) {
					int id = set_id(playerText);
					bool check = check_id(id, pl[player_chance], false);
					if (check) {
						pl[player_chance].money -= (1.05*mortgage_values[id]);
						change_status(&owners[id]);
						pl[player_chance].playerMortProps[id] = 0;
						pl[player_chance].numbMortProps -= 1;
						dispBoughtIcon(id, player_chance, boughtCoods, board_win, size, pl);
						pl[player_chance].playerValue += prop_cost[id];
						window_um.close();
					}
					else {
						sf::RenderWindow window1(sf::VideoMode(500, 100), "Error message");
						sf::Text text;
						text.setFont(font);
						text.setString("Please enter correct id.");
						text.setFillColor(sf::Color::White);
						text.setPosition(100, 30);
						while (window1.isOpen()) {
							sf::Event event1;
							while (window1.pollEvent(event1)) {

								if (event1.type == sf::Event::Closed) {

									window1.close();
								}
							}
							window1.clear();
							window1.draw(text);
							window1.display();
							window_um.close();
						}
					}

				}
			}
		}


		window_um.clear();
		window_um.draw(background);
		window_um.draw(text_um1);
		for (int j = 0; j < 40; j++) {
			window_um.draw(text_um2[j]);
		}
		window_um.draw(text_um3);
		window_um.draw(box);
		window_um.draw(playerText);
		window_um.display();
	}

}
