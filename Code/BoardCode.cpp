#include <SFML/Graphics.hpp>
#include<iostream>
#include"BoardCode.h"
#include "players.h"
#include <sstream>
#include <string>
#include "properties.h"
sf::CircleShape boughtIcon[40];
sf::Sprite house_sprite[40];
sf::Texture house;
sf::Text num[40];
sf::Text text_m[40];
sf::Font font0;
sf::RectangleShape chance_i(sf::Vector2f(100.f, 100.f));

void make_board(sf::RenderWindow& board_win,player pl[],int sz)
{
	//sf::RenderWindow board_win(sf::VideoMode(1440, 960), "Monopoly");
	sf::Texture texture;
	if (!texture.loadFromFile("../Images/Go.png")) {
		std::cout<<"Loading Failed"<<std::endl;
	}
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setScale(0.416f, 0.37f);
	sprite.setPosition(sf::Vector2f(1135.f, 835.f));

	sf::Texture texture2;
	if (!texture2.loadFromFile("../Images/jail.jpeg")) {
		std::cout<<"Loading Failed"<<std::endl;
	}
	sf::Sprite sprite2;
	sprite2.setTexture(texture2);
	sprite2.setScale(0.158f, 0.159f);
	sprite2.setPosition(sf::Vector2f(180.f, 835.f));

	sf::Texture texture3;
	if (!texture3.loadFromFile("../Images/Free parking.jpeg")) {
		std::cout<<"Loading Failed"<<std::endl;
	}
	sf::Sprite sprite3;
	sprite3.setTexture(texture3);
	sprite3.setScale(0.191f, 0.120f);
	sprite3.setPosition(sf::Vector2f(295.f, 125.f));
	sprite3.setRotation(180.f);

	sf::Texture texture4;
	if (!texture4.loadFromFile("../Images/GO to jail.png")) {
		std::cout<<"Loading Failed"<<std::endl;
	}
	sf::Sprite sprite4;
	sprite4.setTexture(texture4);
	sprite4.setScale(0.55f, 0.47f);
	sprite4.setPosition(sf::Vector2f(1260.f, 125.f));
	sprite4.setRotation(180.f);

	sf::Texture texture5;
	if (!texture5.loadFromFile("../Images/Chance Tile.jpeg")) {
		std::cout<<"Loading Failed"<<std::endl;
	}
	sf::Sprite sprite5_1;
	sprite5_1.setTexture(texture5);
	sprite5_1.setScale(0.51f, 0.4f);
	sprite5_1.setPosition(sf::Vector2f(398.f, 835.f));

	sf::Sprite sprite5_2;
	sprite5_2.setTexture(texture5);
	sprite5_2.setScale(0.5f, 0.41f);
	sprite5_2.setPosition(sf::Vector2f(479.f, 125.f));
	sprite5_2.setRotation(180.f);
	
	sf::Sprite sprite5_3;
	sprite5_3.setTexture(texture5);
	sprite5_3.setScale(0.41f, 0.49f);
	sprite5_3.setPosition(sf::Vector2f(1134.5f, 591.669f));
	sprite5_3.setRotation(270.f);

	sf::Texture texture6;
	if (!texture6.loadFromFile("../Images/Community chest.jpeg")) {
		std::cout<<"Loading Failed"<<std::endl;
	}
	sf::Sprite sprite6_1;
	sprite6_1.setTexture(texture6);
	sprite6_1.setScale(0.56f, 0.42f);
	sprite6_1.setPosition(sf::Vector2f(950.554f, 835.f));
	//200.0f, 290.554f
	sf::Sprite sprite6_2;
	sprite6_2.setTexture(texture6);
	sprite6_2.setScale(0.5f, 0.47f);
	sprite6_2.setPosition(sf::Vector2f(295.0f, 290.554f));
	sprite6_2.setRotation(90.f);

	sf::Sprite sprite6_3;
	sprite6_3.setTexture(texture6);
	sprite6_3.setScale(0.5f, 0.5f);
	sprite6_3.setPosition(sf::Vector2f(1135.0f, 358.f));
	sprite6_3.setRotation(270.f);

	sf::Texture texture7;
	if (!texture7.loadFromFile("../Images/waterworks.jpeg")) {
		std::cout<<"Loading Failed"<<std::endl;
	}
	sf::Sprite sprite7;
	sprite7.setTexture(texture7);
	sprite7.setScale(0.61f, 0.4f);
	sprite7.setPosition(sf::Vector2f(944.f, 125.f));
	sprite7.setRotation(180.f);

	sf::Texture texture8;
	if (!texture8.loadFromFile("../Images/luxury tax.jpeg")) {
		std::cout<<"Loading Failed"<<std::endl;
	}
	sf::Sprite sprite8;
	sprite8.setTexture(texture8);
	sprite8.setScale(0.19f, 0.24f);
	sprite8.setPosition(sf::Vector2f(1135.f, 747.f));
	sprite8.setRotation(270.f);
	//295.f, 757.223f
	sf::Texture texture9;
	if (!texture9.loadFromFile("../Images/electric company.jpeg")) {
		std::cout<<"Loading Failed"<<std::endl;
	}
	sf::Sprite sprite9;
	sprite9.setTexture(texture9);
	sprite9.setScale(0.5f, 0.4f);
	sprite9.setPosition(sf::Vector2f(295.f, 678.f));
	sprite9.setRotation(90.f);


	sf::Font font;
	if (!font.loadFromFile("../Fonts/TrajanPro-Regular.ttf"))
	{
		std::cout<<"Loading Failed"<<std::endl;
	}

	sf::Font font2;
	if (!font2.loadFromFile("../Fonts/futur.ttf"))
	{
		std::cout<<"Loading Failed"<<std::endl;
	}

	sf::Font font3;
	if (!font3.loadFromFile("../Fonts/Champagne & Limousines.ttf"))
	{
		std::cout<<"Loading Failed"<<std::endl;
	}
	
	sf::RectangleShape rectangle1(sf::Vector2f(1080.f, 920.f));
	rectangle1.setPosition(180.0f, 20.f);
	rectangle1.setOutlineThickness(10.f);
	rectangle1.setOutlineColor(sf::Color::Cyan);
	rectangle1.setFillColor(sf::Color::Black);

	sf::RectangleShape rectangle2(sf::Vector2f(920.f, 10.f));
	rectangle2.setPosition(305.0f, 20.f);
	rectangle2.setFillColor(sf::Color::Cyan);
	rectangle2.setRotation(90.f);
	//170 thickness from edge for a line.

	sf::RectangleShape rectangle3(sf::Vector2f(920.f, 10.f));
	rectangle3.setPosition(1135.0f, 20.f);
	rectangle3.setFillColor(sf::Color::Cyan);
	rectangle3.setRotation(90.f);

	sf::RectangleShape rectangle4(sf::Vector2f(1080.f, 10.f));
	rectangle4.setPosition(180.0f, 125.f);
	rectangle4.setFillColor(sf::Color::Cyan);

	sf::RectangleShape rectangle5(sf::Vector2f(1080.f, 10.f));
	rectangle5.setPosition(180.0f, 825.f);
	rectangle5.setFillColor(sf::Color::Cyan);

	//rectangle left side

	sf::RectangleShape rectangle6_1(sf::Vector2f(125.f, 10.f));
	rectangle6_1.setPosition(180.0f, 747.216f);
	rectangle6_1.setFillColor(sf::Color::Cyan);

	sf::RectangleShape rectangle6_2(sf::Vector2f(125.f, 10.f));
	rectangle6_2.setPosition(180.0f, 669.439f);
	rectangle6_2.setFillColor(sf::Color::Cyan);

	sf::RectangleShape rectangle6_3(sf::Vector2f(125.f, 10.f));
	rectangle6_3.setPosition(180.0f, 591.662f);
	rectangle6_3.setFillColor(sf::Color::Cyan);
	
	sf::RectangleShape rectangle6_4(sf::Vector2f(125.f, 10.f));
	rectangle6_4.setPosition(180.0f, 513.885f);
	rectangle6_4.setFillColor(sf::Color::Cyan);

	sf::RectangleShape rectangle6_5(sf::Vector2f(125.f, 10.f));
	rectangle6_5.setPosition(180.0f, 436.108f);
	rectangle6_5.setFillColor(sf::Color::Cyan);

	sf::RectangleShape rectangle6_6(sf::Vector2f(125.f, 10.f));
	rectangle6_6.setPosition(180.0f, 358.331f);
	rectangle6_6.setFillColor(sf::Color::Cyan);

	sf::RectangleShape rectangle6_7(sf::Vector2f(125.f, 10.f));
	rectangle6_7.setPosition(180.0f, 280.554f);
	rectangle6_7.setFillColor(sf::Color::Cyan);

	sf::RectangleShape rectangle6_8(sf::Vector2f(125.f, 10.f));
	rectangle6_8.setPosition(180.0f, 202.777f);
	rectangle6_8.setFillColor(sf::Color::Cyan);

	sf::RectangleShape rectangle6_9(sf::Vector2f(125.f, 10.f));
	rectangle6_9.setPosition(180.0f, 125.0f);
	rectangle6_9.setFillColor(sf::Color::Cyan);

	//77.777 left for each one.

	// right side ones
	sf::RectangleShape rectangle7_1(sf::Vector2f(125.f, 10.f));
	rectangle7_1.setPosition(1135.0f, 747.216f);
	rectangle7_1.setFillColor(sf::Color::Cyan);

	sf::RectangleShape rectangle7_2(sf::Vector2f(125.f, 10.f));
	rectangle7_2.setPosition(1135.0f, 669.439f);
	rectangle7_2.setFillColor(sf::Color::Cyan);

	sf::RectangleShape rectangle7_3(sf::Vector2f(125.f, 10.f));
	rectangle7_3.setPosition(1135.0f, 591.662f);
	rectangle7_3.setFillColor(sf::Color::Cyan);

	sf::RectangleShape rectangle7_4(sf::Vector2f(125.f, 10.f));
	rectangle7_4.setPosition(1135.0f, 513.885f);
	rectangle7_4.setFillColor(sf::Color::Cyan);

	sf::RectangleShape rectangle7_5(sf::Vector2f(125.f, 10.f));
	rectangle7_5.setPosition(1135.0f, 436.108f);
	rectangle7_5.setFillColor(sf::Color::Cyan);

	sf::RectangleShape rectangle7_6(sf::Vector2f(125.f, 10.f));
	rectangle7_6.setPosition(1135.0f, 358.331f);
	rectangle7_6.setFillColor(sf::Color::Cyan);

	sf::RectangleShape rectangle7_7(sf::Vector2f(125.f, 10.f));
	rectangle7_7.setPosition(1135.0f, 280.554f);
	rectangle7_7.setFillColor(sf::Color::Cyan);

	sf::RectangleShape rectangle7_8(sf::Vector2f(125.f, 10.f));
	rectangle7_8.setPosition(1135.0f, 202.777f);
	rectangle7_8.setFillColor(sf::Color::Cyan);

	sf::RectangleShape rectangle7_9(sf::Vector2f(125.f, 10.f));
	rectangle7_9.setPosition(1135.0f, 125.0f);
	rectangle7_9.setFillColor(sf::Color::Cyan);


	
	sf::RectangleShape rectangle8_1(sf::Vector2f(105.f, 10.f));
	rectangle8_1.setPosition(397.222f, 20.f);
	rectangle8_1.setFillColor(sf::Color::Cyan);
	rectangle8_1.setRotation(90.f);

	sf::RectangleShape rectangle8_2(sf::Vector2f(105.f, 10.f));
	rectangle8_2.setPosition(489.444f, 20.f);
	rectangle8_2.setFillColor(sf::Color::Cyan);
	rectangle8_2.setRotation(90.f);

	sf::RectangleShape rectangle8_3(sf::Vector2f(105.f, 10.f));
	rectangle8_3.setPosition(581.666f, 20.f);
	rectangle8_3.setFillColor(sf::Color::Cyan);
	rectangle8_3.setRotation(90.f);

	sf::RectangleShape rectangle8_4(sf::Vector2f(105.f, 10.f));
	rectangle8_4.setPosition(673.888f, 20.f);
	rectangle8_4.setFillColor(sf::Color::Cyan);
	rectangle8_4.setRotation(90.f);
	sf::RectangleShape rectangle8_5(sf::Vector2f(105.f, 10.f));
	rectangle8_5.setPosition(766.11f, 20.f);
	rectangle8_5.setFillColor(sf::Color::Cyan);
	rectangle8_5.setRotation(90.f);

	sf::RectangleShape rectangle8_6(sf::Vector2f(105.f, 10.f));
	rectangle8_6.setPosition(858.332f, 20.f);
	rectangle8_6.setFillColor(sf::Color::Cyan);
	rectangle8_6.setRotation(90.f);

	sf::RectangleShape rectangle8_7(sf::Vector2f(105.f, 10.f));
	rectangle8_7.setPosition(950.554f, 20.f);
	rectangle8_7.setFillColor(sf::Color::Cyan);
	rectangle8_7.setRotation(90.f);

	sf::RectangleShape rectangle8_8(sf::Vector2f(105.f, 10.f));
	rectangle8_8.setPosition(1042.774f, 20.f);
	rectangle8_8.setFillColor(sf::Color::Cyan);
	rectangle8_8.setRotation(90.f);

	sf::RectangleShape rectangle8_9(sf::Vector2f(105.f, 10.f));
	rectangle8_9.setPosition(1135.0f, 20.f);
	rectangle8_9.setFillColor(sf::Color::Cyan);
	rectangle8_9.setRotation(90.f);

	//bottom
	sf::RectangleShape rectangle9_1(sf::Vector2f(105.f, 10.f));
	rectangle9_1.setPosition(397.222f, 835.f);
	rectangle9_1.setFillColor(sf::Color::Cyan);
	rectangle9_1.setRotation(90.f);

	sf::RectangleShape rectangle9_2(sf::Vector2f(105.f, 10.f));
	rectangle9_2.setPosition(489.444f, 835.f);
	rectangle9_2.setFillColor(sf::Color::Cyan);
	rectangle9_2.setRotation(90.f);

	sf::RectangleShape rectangle9_3(sf::Vector2f(105.f, 10.f));
	rectangle9_3.setPosition(581.666f, 835.f);
	rectangle9_3.setFillColor(sf::Color::Cyan);
	rectangle9_3.setRotation(90.f);

	sf::RectangleShape rectangle9_4(sf::Vector2f(105.f, 10.f));
	rectangle9_4.setPosition(673.888f, 835.f);
	rectangle9_4.setFillColor(sf::Color::Cyan);
	rectangle9_4.setRotation(90.f);

	sf::RectangleShape rectangle9_5(sf::Vector2f(105.f, 10.f));
	rectangle9_5.setPosition(766.11f, 835.f);
	rectangle9_5.setFillColor(sf::Color::Cyan);
	rectangle9_5.setRotation(90.f);

	sf::RectangleShape rectangle9_6(sf::Vector2f(105.f, 10.f));
	rectangle9_6.setPosition(858.332f, 835.f);
	rectangle9_6.setFillColor(sf::Color::Cyan);
	rectangle9_6.setRotation(90.f);

	sf::RectangleShape rectangle9_7(sf::Vector2f(105.f, 10.f));
	rectangle9_7.setPosition(950.554f, 835.f);
	rectangle9_7.setFillColor(sf::Color::Cyan);
	rectangle9_7.setRotation(90.f);

	sf::RectangleShape rectangle9_8(sf::Vector2f(105.f, 10.f));
	rectangle9_8.setPosition(1042.774f, 835.f);
	rectangle9_8.setFillColor(sf::Color::Cyan);
	rectangle9_8.setRotation(90.f);

	sf::RectangleShape rectangle9_9(sf::Vector2f(105.f, 10.f));
	rectangle9_9.setPosition(1135.0f, 835.f);
	rectangle9_9.setFillColor(sf::Color::Cyan);
	rectangle9_9.setRotation(90.f);

	//Left Colored

	sf::RectangleShape rectangle_red1(sf::Vector2f(67.777f, 20.f));
	rectangle_red1.setPosition(295.f, 757.223f);
	rectangle_red1.setFillColor(sf::Color::Red);
	rectangle_red1.setRotation(90.f);
	sf::Text text2;
	text2.setFont(font3);
	text2.setString("LUDHIANA\n\n\n\n\n\t $140");
	text2.setPosition(275.0f, 762.f);
	text2.setRotation(90.0f);
	text2.setCharacterSize(13);
	text2.setFillColor(sf::Color::White);
	text2.setStyle(sf::Text::Bold);
	
	sf::Text text100;
	text100.setFont(font2);
	text100.setString("D");
	text100.setPosition(1185.0f, 865.f);

	sf::RectangleShape rectangle_red2(sf::Vector2f(67.777f, 20.f));
	rectangle_red2.setPosition(295.f, 601.669f);
	rectangle_red2.setFillColor(sf::Color::Red);
	rectangle_red2.setRotation(90.f);
	sf::Text text3;
	text3.setFont(font3);
	text3.setString("PATNA\n\n\n\n $140");
	text3.setPosition(275.0f, 615.f);
	text3.setRotation(90.0f);
	text3.setCharacterSize(15);
	text3.setFillColor(sf::Color::White);
	text3.setStyle(sf::Text::Bold);

	sf::RectangleShape rectangle_red3(sf::Vector2f(67.777f, 20.f));
	rectangle_red3.setPosition(295.f, 523.892f);
	rectangle_red3.setFillColor(sf::Color::Red);
	rectangle_red3.setRotation(90.f);
	sf::Text text4;
	text4.setFont(font3);
	text4.setString("BHOPAL\n\n\n\n $160");
	text4.setPosition(275.0f, 533.f);
	text4.setRotation(90.0f);
	text4.setCharacterSize(15);
	text4.setFillColor(sf::Color::White);
	text4.setStyle(sf::Text::Bold);
	
	//orange
	
	sf::RectangleShape rectangle_pink1(sf::Vector2f(67.777f, 20.f));
	rectangle_pink1.setPosition(295.f, 368.338f);
	rectangle_pink1.setFillColor(sf::Color::Magenta);
	rectangle_pink1.setRotation(90.f);
	sf::Text text5;
	text5.setFont(font3);
	text5.setString("INDORE\n\n\n\n $150");
	text5.setPosition(275.0f, 377.f);
	text5.setRotation(90.0f);
	text5.setCharacterSize(15);
	text5.setFillColor(sf::Color::White);
	text5.setStyle(sf::Text::Bold);

	sf::RectangleShape rectangle_pink2(sf::Vector2f(67.777f, 20.f));
	rectangle_pink2.setPosition(295.f, 212.784f);
	rectangle_pink2.setFillColor(sf::Color::Magenta);
	rectangle_pink2.setRotation(90.f);
	sf::Text text6;
	text6.setFont(font3);
	text6.setString("NAGPUR\n\n\n\n $160");
	text6.setPosition(275.0f, 221.f);
	text6.setRotation(90.0f);
	text6.setCharacterSize(15);
	text6.setFillColor(sf::Color::White);
	text6.setStyle(sf::Text::Bold);

	sf::RectangleShape rectangle_pink3(sf::Vector2f(67.777f, 20.f));
	rectangle_pink3.setPosition(295.f, 135.007f);
	rectangle_pink3.setFillColor(sf::Color::Magenta);
	rectangle_pink3.setRotation(90.f);
	sf::Text text7;
	text7.setFont(font3);
	text7.setString("KOCHI\n\n\n\n $200");
	text7.setPosition(275.0f, 150.f);
	text7.setRotation(90.0f);
	text7.setCharacterSize(15);
	text7.setFillColor(sf::Color::White);
	text7.setStyle(sf::Text::Bold);
	
	//gold
	sf::RectangleShape rectangle_gold1(sf::Vector2f(82.222f, 20.f));
	rectangle_gold1.setPosition(305.f, 105.f);
	rectangle_gold1.setFillColor(sf::Color(253, 227, 167));
	sf::Text text8;
	text8.setFont(font3);
	text8.setString("LUCKNOW\n\n\n\t $220");
	text8.setPosition(380.222f, 103.f);
	text8.setRotation(180.0f);
	text8.setCharacterSize(15);
	text8.setFillColor(sf::Color::White);
	text8.setStyle(sf::Text::Bold);

	sf::RectangleShape rectangle_gold2(sf::Vector2f(82.222f, 20.f));
	rectangle_gold2.setPosition(489.444f, 105.f);
	rectangle_gold2.setFillColor(sf::Color(253, 227, 167));
	sf::Text text9;
	text9.setFont(font3);
	text9.setString("CHANDIGARH\n\n\n\n\t $220");
	text9.setPosition(569.f, 103.f);
	text9.setRotation(180.0f);
	text9.setCharacterSize(13);
	text9.setFillColor(sf::Color::White);
	text9.setStyle(sf::Text::Bold);

	sf::RectangleShape rectangle_gold3(sf::Vector2f(82.222f, 20.f));
	rectangle_gold3.setPosition(581.66f, 105.f);
	rectangle_gold3.setFillColor(sf::Color(253, 227, 167)); 
	sf::Text text10;
	text10.setFont(font3);
	text10.setString("JAIPUR\n\n\n$240");
	text10.setPosition(645.f, 103.f);
	text10.setRotation(180.0f);
	text10.setCharacterSize(15);
	text10.setFillColor(sf::Color::White);
	text10.setStyle(sf::Text::Bold);

	//Yellow
	sf::RectangleShape rectangle_yellow1(sf::Vector2f(82.222f, 20.f));
	rectangle_yellow1.setPosition(766.11f, 105.f);
	rectangle_yellow1.setFillColor(sf::Color(255, 203, 5));
	sf::Text text11;
	text11.setFont(font3);
	text11.setString("PUNE\n\n\n$220");
	text11.setPosition(828.f, 103.f);
	text11.setRotation(180.0f);
	text11.setCharacterSize(17);
	text11.setFillColor(sf::Color::White);
	text11.setStyle(sf::Text::Bold);

	sf::RectangleShape rectangle_yellow2(sf::Vector2f(82.222f, 20.f));
	rectangle_yellow2.setPosition(950.554f, 105.f);
	rectangle_yellow2.setFillColor(sf::Color(255, 203, 5));
	sf::Text text12;
	text12.setFont(font3);
	text12.setString("HYDERABAD\n\n\n\t $325");
	text12.setPosition(1028.f, 103.f);
	text12.setRotation(180.0f);
	text12.setCharacterSize(14);
	text12.setFillColor(sf::Color::White);
	text12.setStyle(sf::Text::Bold);

	sf::RectangleShape rectangle_yellow3(sf::Vector2f(82.222f, 20.f));
	rectangle_yellow3.setPosition(1042.774f, 105.f);
	rectangle_yellow3.setFillColor(sf::Color(255, 203, 5));
	sf::Text text13;
	text13.setFont(font3);
	text13.setString("AHMEDABAD\n\n\n\t $280");
	text13.setPosition(1124.f, 103.f);
	text13.setRotation(180.0f);
	text13.setCharacterSize(14);
	text13.setFillColor(sf::Color::White);
	text13.setStyle(sf::Text::Bold);

	//Right Colored
	//blue
	sf::RectangleShape rectangle_blue1(sf::Vector2f(67.777f, 20.f));
	rectangle_blue1.setPosition(1155.f, 757.223f);
	rectangle_blue1.setFillColor(sf::Color::Blue);
	rectangle_blue1.setRotation(90.f);
	sf::Text text18;
	text18.setFont(font3);
	text18.setString("MUMBAI\n\n\n\n $350");
	text18.setPosition(1155.f, 817.f);
	text18.setRotation(270.0f);
	text18.setCharacterSize(15);
	text18.setFillColor(sf::Color::White);
	text18.setStyle(sf::Text::Bold);

	sf::RectangleShape rectangle_blue2(sf::Vector2f(67.777f, 20.f));
	rectangle_blue2.setPosition(1155.f, 601.669f);
	rectangle_blue2.setFillColor(sf::Color::Blue);
	rectangle_blue2.setRotation(90.f);
	sf::Text text17;
	text17.setFont(font3);
	text17.setString("DELHI\n\n\n\n$325");
	text17.setPosition(1155.f, 658.f);
	text17.setRotation(270.0f);
	text17.setCharacterSize(16);
	text17.setFillColor(sf::Color::White);
	text17.setStyle(sf::Text::Bold);

	//green
	sf::RectangleShape rectangle_green1(sf::Vector2f(67.777f, 20.f));
	rectangle_green1.setPosition(1155.f, 368.338f);
	rectangle_green1.setFillColor(sf::Color::Green);
	rectangle_green1.setRotation(90.f);
	sf::Text text16;
	text16.setFont(font3);
	text16.setString("BANGALORE\n\n\n\n\n\t $330");
	text16.setPosition(1155.f, 437.f);
	text16.setRotation(270.0f);
	text16.setCharacterSize(13);
	text16.setFillColor(sf::Color::White);
	text16.setStyle(sf::Text::Bold);

	sf::RectangleShape rectangle_green2(sf::Vector2f(67.777f, 20.f));
	rectangle_green2.setPosition(1155.f, 212.784f);
	rectangle_green2.setFillColor(sf::Color::Green);
	rectangle_green2.setRotation(90.f); 
	sf::Text text15;
	text15.setFont(font3);
	text15.setString("CHENNAI\n\n\n\n  $320");
	text15.setPosition(1155.f, 279.f);
	text15.setRotation(270.0f);
	text15.setCharacterSize(15);
	text15.setFillColor(sf::Color::White);
	text15.setStyle(sf::Text::Bold);

	sf::RectangleShape rectangle_green3(sf::Vector2f(67.777f, 20.f));
	rectangle_green3.setPosition(1155.f, 135.007f);
	rectangle_green3.setFillColor(sf::Color::Green);
	rectangle_green3.setRotation(90.f);
	sf::Text text14;
	text14.setFont(font3);
	text14.setString("KOLKATA\n\n\n\n  $320");
	text14.setPosition(1155.f, 200.f);
	text14.setRotation(270.0f);
	text14.setCharacterSize(15);
	text14.setFillColor(sf::Color::White);
	text14.setStyle(sf::Text::Bold);

	//bottom colored
	//darker green
	sf::RectangleShape rectangle_drgrn1(sf::Vector2f(82.222f, 20.f));
	rectangle_drgrn1.setPosition(305.f, 835.f);
	rectangle_drgrn1.setFillColor(sf::Color(27, 163, 157));
	sf::Text text21;
	text21.setFont(font3);
	text21.setString("VADODARA\n\n\n\t $100");
	text21.setPosition(308.f, 855.f);
	text21.setCharacterSize(15);
	text21.setFillColor(sf::Color::White);
	text21.setStyle(sf::Text::Bold);

	sf::RectangleShape rectangle_drgrn2(sf::Vector2f(82.222f, 20.f));
	rectangle_drgrn2.setPosition(489.444f, 835.f);
	rectangle_drgrn2.setFillColor(sf::Color(27, 163, 157));
	sf::Text text22;
	text22.setFont(font3);
	text22.setString("AGRA \n\n\n$100");
	text22.setPosition(509.f, 855.f);
	text22.setCharacterSize(17);
	text22.setFillColor(sf::Color::White);
	text22.setStyle(sf::Text::Bold);

	sf::RectangleShape rectangle_drgrn3(sf::Vector2f(82.222f, 20.f));
	rectangle_drgrn3.setPosition(581.66f, 835.f);
	rectangle_drgrn3.setFillColor(sf::Color(27, 163, 157));
	sf::Text text23;
	text23.setFont(font3);
	text23.setString("PANAJI\n\n\n $100");
	text23.setPosition(601.f, 855.f);
	text23.setCharacterSize(15);
	text23.setFillColor(sf::Color::White);
	text23.setStyle(sf::Text::Bold);

	//shamrock

	sf::RectangleShape rectangle_shamrock1(sf::Vector2f(82.222f, 20.f));
	rectangle_shamrock1.setPosition(857.778f, 835.f);
	rectangle_shamrock1.setFillColor(sf::Color(135, 211, 124));
	sf::Text text20;
	text20.setFont(font3);
	text20.setString("BHUBANESH\n\t\t\t-WAR\n\n\t $80");
	text20.setPosition(858.f, 855.f);
	text20.setCharacterSize(13);
	text20.setFillColor(sf::Color::White);
	text20.setStyle(sf::Text::Bold);

	sf::RectangleShape rectangle_shamrock2(sf::Vector2f(82.222f, 20.f));
	rectangle_shamrock2.setPosition(1042.774f, 835.f);
	rectangle_shamrock2.setFillColor(sf::Color(135, 211, 124));
	sf::Text text19;
	text19.setFont(font3);
	text19.setString("GUWAHATI\n\n\n\t $60");
	text19.setPosition(1052.f, 855.f);
	text19.setCharacterSize(15);
	text19.setFillColor(sf::Color::White);
	text19.setStyle(sf::Text::Bold);

	//Start the text
	sf::Text text;
	text.setFont(font2);
	text.setString("Monopoly");
	text.setPosition(555.0f, 575.f);
	text.setRotation(315.0f);
	text.setCharacterSize(48);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text.setLetterSpacing(3);

	sf::Text comm;
	comm.setFont(font);
	comm.setString(" Community Chest ");
	comm.setPosition(640.0f, 230.f);
	comm.setRotation(135.0f);
	comm.setCharacterSize(24);
	comm.setStyle(sf::Text::Bold | sf::Text::Underlined);
	
	sf::Text chan;
	chan.setFont(font);
	chan.setString("Chance");
	chan.setPosition(815.0f, 660.f);
	chan.setRotation(315.0f);
	chan.setCharacterSize(24);
	chan.setStyle(sf::Text::Bold | sf::Text::Underlined);

	sf::RectangleShape comm_rect(sf::Vector2f(300.f, 187.5f));
	comm_rect.setOutlineThickness(1.f);
	comm_rect.setRotation(315.0f);
	comm_rect.setPosition(360.f, 360.f);
	comm_rect.setOutlineColor(sf::Color(171, 183, 183));
	comm_rect.setFillColor(sf::Color::Black);
	comm_rect.setOutlineThickness(2.f);

	sf::RectangleShape chan_rect(sf::Vector2f(300.f, 187.5f));
	chan_rect.setOutlineThickness(1.f);
	chan_rect.setRotation(315.0f);
	chan_rect.setPosition(700.f, 680.f);
	chan_rect.setOutlineColor(sf::Color(171, 183, 183));
	chan_rect.setFillColor(sf::Color::Black);
	chan_rect.setOutlineThickness(2.f);

	sf::Text text27;
	text27.setFont(font3);
	text27.setString("Howrah \n Station\n\n\n\n $200");
	text27.setPosition(295.0f, 454.f);
	text27.setRotation(90.0f);
	text27.setCharacterSize(15);
	text27.setFillColor(sf::Color::White);
	text27.setStyle(sf::Text::Bold);
	sf::Texture texture10;
	if (!texture10.loadFromFile("../Images/railroad image.png")) {
		std::cout<<"Loading Failed"<<std::endl;
	}
	sf::Sprite sprite10;
	sprite10.setTexture(texture10);
	sprite10.setScale(0.125f, 0.134f);
	sprite10.setPosition(sf::Vector2f(255.0f, 444.f));
	sprite10.setRotation(90.f);

	sf::Text text24;
	text24.setFont(font3);
	text24.setString("Chennai\n Central\n\n\n\n $200");
	text24.setPosition(684.0f, 835.f);
	text24.setCharacterSize(15);
	text24.setFillColor(sf::Color::White);
	text24.setStyle(sf::Text::Bold);
	sf::Sprite sprite11;
	sprite11.setTexture(texture10);
	sprite11.setScale(0.135f, 0.134f);
	sprite11.setPosition(sf::Vector2f(674.0f, 875.f));
	
	sf::Text text25;
	text25.setFont(font3);
	text25.setString("Mumbai\nRailways\n\n\n\n $200");
	text25.setPosition(1135.0f, 504.f);
	text25.setRotation(270.0f);
	text25.setCharacterSize(15);
	text25.setFillColor(sf::Color::White);
	text25.setStyle(sf::Text::Bold);
	sf::Sprite sprite12;
	sprite12.setTexture(texture10);
	sprite12.setScale(0.116f, 0.134f);
	sprite12.setPosition(sf::Vector2f(1175.0f, 514.f));
	sprite12.setRotation(270.f);
	
	sf::Text text26;
	text26.setFont(font3);
	text26.setString("New Delhi\nRailways\n\n\n\n $200");
	text26.setPosition(746.0f, 123.f);
	text26.setRotation(180.0f);
	text26.setCharacterSize(15);
	text26.setFillColor(sf::Color::White);
	text26.setStyle(sf::Text::Bold);
	sf::Sprite sprite13;
	sprite13.setTexture(texture10);
	sprite13.setScale(0.135f, 0.134f);
	sprite13.setPosition(sf::Vector2f(756.0f, 83.f));
	sprite13.setRotation(180.f);

	sf::Text text28;
	text28.setFont(font3);
	text28.setString(" TAX \n REFUND\n Get\n $150\n from the\n Bank.");
	text28.setPosition(776.0f, 835.f);
	text28.setCharacterSize(15);
	text28.setFillColor(sf::Color(240, 255, 0));
	text28.setStyle(sf::Text::Bold);
	
	rectangle1b.setSize(sf::Vector2f(115.f, 60.f));
	rectangle1b.setFillColor(sf::Color(253,227,167));
	rectangle1b.setPosition(25.0f, 20.0f);
	rectangle1b.setOutlineThickness(5);
	rectangle1b.setOutlineColor(sf::Color(255,10,100));

	text1b.setFont(font);
	text1b.setString("ROLL");
	text1b.setCharacterSize(30);
	text1b.setPosition(42.0f, 35.0f);
	text1b.setStyle(sf::Text::Bold);
	text1b.setFillColor(sf::Color::Black);

	rectangle2b.setSize(sf::Vector2f(115.f, 60.f));
	rectangle2b.setFillColor(sf::Color::Red);
	rectangle2b.setPosition(25.0f, 120.0f);
	rectangle2b.setOutlineThickness(5);
	rectangle2b.setOutlineColor(sf::Color::White);

	text2b.setFont(font);
	text2b.setString("TRADE");
	text2b.setCharacterSize(15);
	text2b.setPosition(45.0f, 140.0f);
	text2b.setStyle(sf::Text::Bold);

	rectangle3b.setSize(sf::Vector2f(115.f, 60.f));
	rectangle3b.setFillColor(sf::Color::Red);
	rectangle3b.setPosition(25.0f, 220.0f);
	rectangle3b.setOutlineThickness(5);
	rectangle3b.setOutlineColor(sf::Color::White);

	text3b.setFont(font);
	text3b.setString("BUILD");
	text3b.setCharacterSize(15);
	text3b.setPosition(45.0f, 240.0f);
	text3b.setStyle(sf::Text::Bold);

	rectangle4b.setSize(sf::Vector2f(115.f, 60.f));
	rectangle4b.setFillColor(sf::Color::Red);
	rectangle4b.setPosition(25.0f, 320.0f);
	rectangle4b.setOutlineThickness(5);
	rectangle4b.setOutlineColor(sf::Color::White);

	text4b.setFont(font);
	text4b.setString("SELL");
	text4b.setCharacterSize(15);
	text4b.setPosition(55.0f, 339.0f);
	text4b.setStyle(sf::Text::Bold);

	rectangle5b.setSize(sf::Vector2f(115.f, 60.f));
	rectangle5b.setFillColor(sf::Color::Red);
	rectangle5b.setPosition(25.0f, 420.0f);
	rectangle5b.setOutlineThickness(5);
	rectangle5b.setOutlineColor(sf::Color::White);

	text5b.setFont(font);
	text5b.setString("MORTGAGE");
	text5b.setCharacterSize(15);
	text5b.setPosition(26.0f, 440.0f);
	text5b.setStyle(sf::Text::Bold);

	rectangle6b.setSize(sf::Vector2f(115.f, 60.f));
	rectangle6b.setFillColor(sf::Color::Red);
	rectangle6b.setPosition(25.0f, 520.0f);
	rectangle6b.setOutlineThickness(5);
	rectangle6b.setOutlineColor(sf::Color::White);

	text6b.setFont(font);
	text6b.setString("UNMORT-\nGAGE");
	text6b.setCharacterSize(15);
	text6b.setPosition(30.0f, 535.0f);
	text6b.setStyle(sf::Text::Bold);


		board_win.clear();
		//board_win.draw(sprite2);
	
		board_win.draw(rectangle1);
		board_win.draw(rectangle2);
		board_win.draw(rectangle3);
		board_win.draw(rectangle4);
		board_win.draw(rectangle5);
		
		board_win.draw(rectangle6_1);
		board_win.draw(rectangle6_2);
		board_win.draw(rectangle6_3);
		board_win.draw(rectangle6_4);
		board_win.draw(rectangle6_5);
		board_win.draw(rectangle6_6);
		board_win.draw(rectangle6_7);
		board_win.draw(rectangle6_8);
		board_win.draw(rectangle6_9);

		board_win.draw(rectangle7_1);
		board_win.draw(rectangle7_2);
		board_win.draw(rectangle7_3);
		board_win.draw(rectangle7_4);
		board_win.draw(rectangle7_5);
		board_win.draw(rectangle7_6);
		board_win.draw(rectangle7_7);
		board_win.draw(rectangle7_8);
		board_win.draw(rectangle7_9);

		board_win.draw(rectangle8_1);
		board_win.draw(rectangle8_2);
		board_win.draw(rectangle8_3);
		board_win.draw(rectangle8_4);
		board_win.draw(rectangle8_5);
		board_win.draw(rectangle8_6);
		board_win.draw(rectangle8_7);
		board_win.draw(rectangle8_8);
		board_win.draw(rectangle8_9);

		board_win.draw(rectangle9_1);
		board_win.draw(rectangle9_2);
		board_win.draw(rectangle9_3);
		board_win.draw(rectangle9_4);
		board_win.draw(rectangle9_5);
		board_win.draw(rectangle9_6);
		board_win.draw(rectangle9_7);
		board_win.draw(rectangle9_8);
		board_win.draw(rectangle9_9);

		board_win.draw(rectangle_red1);
		board_win.draw(rectangle_red2);
		board_win.draw(rectangle_red3);
		
		board_win.draw(rectangle_pink1);
		board_win.draw(rectangle_pink2);
		board_win.draw(rectangle_pink3);

		board_win.draw(rectangle_gold1);
		board_win.draw(rectangle_gold2);
		board_win.draw(rectangle_gold3);

		board_win.draw(rectangle_yellow1);
		board_win.draw(rectangle_yellow2);
		board_win.draw(rectangle_yellow3);
		
		board_win.draw(rectangle_green1);
		board_win.draw(rectangle_green2);
		board_win.draw(rectangle_green3);
		
		board_win.draw(rectangle_blue1);
		board_win.draw(rectangle_blue2);
		
		board_win.draw(rectangle_drgrn1);
		board_win.draw(rectangle_drgrn2);
		board_win.draw(rectangle_drgrn3);

		board_win.draw(rectangle_shamrock1);
		board_win.draw(rectangle_shamrock2);

		board_win.draw(text);
		board_win.draw(sprite);
		board_win.draw(sprite2);
		board_win.draw(sprite3);
		board_win.draw(sprite4);
		board_win.draw(sprite5_1);
		board_win.draw(sprite5_2);
		board_win.draw(sprite5_3);
		board_win.draw(sprite6_1);
		board_win.draw(sprite6_2);
		board_win.draw(sprite6_3);
		board_win.draw(sprite7);
		board_win.draw(sprite8);
		board_win.draw(sprite9);
		board_win.draw(sprite10);
		board_win.draw(sprite11);
		board_win.draw(sprite12);
		board_win.draw(sprite13);

		board_win.draw(text2);
		board_win.draw(text3);
		board_win.draw(text4);
		board_win.draw(text5);
		board_win.draw(text6); 
		board_win.draw(text7);
		board_win.draw(text8);
		board_win.draw(text9);
		board_win.draw(text10);
		board_win.draw(text11);
		board_win.draw(text12);
		board_win.draw(text13);
		board_win.draw(text14);
		board_win.draw(text15);
		board_win.draw(text16);
		board_win.draw(text17);
		board_win.draw(text18);
		board_win.draw(text19);
		board_win.draw(text20);
		board_win.draw(text21);
		board_win.draw(text22);
		board_win.draw(text23);
		board_win.draw(text24);
		board_win.draw(text25);
		board_win.draw(text26);
		board_win.draw(text27);
		board_win.draw(text28);

		board_win.draw(comm_rect);
		board_win.draw(chan_rect);

	        board_win.draw(chance_i);
	
		board_win.draw(comm);
		board_win.draw(chan);
	
	        board_win.draw(rectangle1b);
	        board_win.draw(rectangle2b);
	        board_win.draw(rectangle3b);
	        board_win.draw(rectangle4b);
	        board_win.draw(rectangle5b);
	        board_win.draw(rectangle6b);
	        board_win.draw(text1b);
	        board_win.draw(text2b);
	        board_win.draw(text3b);
	        board_win.draw(text4b);
	        board_win.draw(text5b);
	        board_win.draw(text6b);

		for(int h=0; h<40; h++){
			if(num[h].getFillColor()!=sf::Color(255,0,0,0))
				board_win.draw(house_sprite[h]);
		}

		for(int h=0; h<40; h++)
		{
			
			board_win.draw(num[h]);
			
		}

		for(int i=0;i<sz;i++)
		{
			board_win.draw((pl+i)->icon);
		}

		for(int h=0; h<40; h++){
			if(owners[h]>=1){
				board_win.draw(boughtIcon[h]);
			}
		}
		for(int h=0; h<40; h++){
			if(owners[h]<=-1){
				board_win.draw(text_m[h]);
				}
			}

	if(sz==2){

	std::stringstream ss1;
	std::stringstream ss2;

	ss1 << pl[0].playerName << "\n $ : " << pl[0].money;
	ss2 << pl[1].playerName << "\n $ : " << pl[1].money;

	std::string pl0 = ss1.str();
	std::string pl1 = ss2.str();


  sf::Text pl_name1;
	pl_name1.setFont(font3);
	pl_name1.setString(pl0);
	pl_name1.setPosition(1290.f, 92.f);
	pl_name1.setFillColor(sf::Color(30, 130, 76));
	pl_name1.setCharacterSize(27);

	sf::Text pl_name2;
	pl_name2.setFont(font3);
	pl_name2.setString(pl1);
	pl_name2.setPosition(1290.f, 212.f);
	pl_name2.setFillColor(sf::Color(37, 116, 169));
	pl_name2.setCharacterSize(27);

  sf::RectangleShape pl_rect1(sf::Vector2f(135.f,85.f));
	pl_rect1.setPosition(1287.5, 85.f);
	pl_rect1.setFillColor(sf::Color::Black);
	pl_rect1.setOutlineColor(sf::Color(30, 130, 76));
	pl_rect1.setOutlineThickness(7.f);

	sf::RectangleShape pl_rect2(sf::Vector2f(135.f,85.f));
	pl_rect2.setPosition(1287.5, 205.f);
	pl_rect2.setFillColor(sf::Color::Black);
	pl_rect2.setOutlineColor(sf::Color(37, 116, 169));
	pl_rect2.setOutlineThickness(7.f);

	board_win.draw(pl_rect1);
	board_win.draw(pl_rect2);

	board_win.draw(pl_name1);
	board_win.draw(pl_name2);

  }
  if(sz==3){

std::stringstream ss1;
std::stringstream ss2;
std::stringstream ss3;


ss1 << pl[0].playerName << "\n $ : " << pl[0].money;
ss2 << pl[1].playerName << "\n $ : " << pl[1].money;
ss3 << pl[2].playerName << "\n $ : " << pl[2].money;


std::string pl0 = ss1.str();
std::string pl1 = ss2.str();
std::string pl2 = ss3.str();


	sf::RectangleShape pl_rect1(sf::Vector2f(135.f,85.f));
	pl_rect1.setPosition(1287.5, 85.f);
	pl_rect1.setFillColor(sf::Color::Black);
	pl_rect1.setOutlineColor(sf::Color(30, 130, 76));
	pl_rect1.setOutlineThickness(7.f);

	sf::RectangleShape pl_rect2(sf::Vector2f(135.f,85.f));
	pl_rect2.setPosition(1287.5, 205.f);
	pl_rect2.setFillColor(sf::Color::Black);
	pl_rect2.setOutlineColor(sf::Color(37, 116, 169));
	pl_rect2.setOutlineThickness(7.f);

	sf::RectangleShape pl_rect3(sf::Vector2f(135.f,85.f));
	pl_rect3.setPosition(1287.5, 325.f);
	pl_rect3.setFillColor(sf::Color::Black);
	pl_rect3.setOutlineColor(sf::Color(140, 20, 252));
	pl_rect3.setOutlineThickness(7.f);

	sf::Text pl_name1;
	pl_name1.setFont(font3);
	pl_name1.setString(pl0);
	pl_name1.setPosition(1290.f, 92.f);
	pl_name1.setFillColor(sf::Color(30, 130, 76));
	pl_name1.setCharacterSize(27);

	sf::Text pl_name2;
	pl_name2.setFont(font3);
	pl_name2.setString(pl1);
	pl_name2.setPosition(1290.f, 212.f);
	pl_name2.setFillColor(sf::Color(37, 116, 169));
	pl_name2.setCharacterSize(27);

	sf::Text pl_name3;
	pl_name3.setFont(font3);
	pl_name3.setString(pl2);
	pl_name3.setPosition(1290.f, 332.f);
	pl_name3.setFillColor(sf::Color(140, 20, 252));
	pl_name3.setCharacterSize(27);

		board_win.draw(pl_rect1);
		board_win.draw(pl_rect2);
		board_win.draw(pl_rect3);

		board_win.draw(pl_name1);
		board_win.draw(pl_name2);
		board_win.draw(pl_name3);
  }
  if(sz==4){

std::stringstream ss1;
std::stringstream ss2;
std::stringstream ss3;
std::stringstream ss4;


ss1 << pl[0].playerName << "\n $ : " << pl[0].money;
ss2 << pl[1].playerName << "\n $ : " << pl[1].money;
ss3 << pl[2].playerName << "\n $ : " << pl[2].money;
ss4 << pl[3].playerName << "\n $ : " << pl[3].money;


std::string pl0 = ss1.str();
std::string pl1 = ss2.str();
std::string pl2 = ss3.str();
std::string pl3 = ss4.str();


	sf::RectangleShape pl_rect1(sf::Vector2f(135.f,85.f));
	pl_rect1.setPosition(1287.5, 85.f);
	pl_rect1.setFillColor(sf::Color::Black);
	pl_rect1.setOutlineColor(sf::Color(30, 130, 76));
	pl_rect1.setOutlineThickness(7.f);

	sf::RectangleShape pl_rect2(sf::Vector2f(135.f,85.f));
	pl_rect2.setPosition(1287.5, 205.f);
	pl_rect2.setFillColor(sf::Color::Black);
	pl_rect2.setOutlineColor(sf::Color(37, 116, 169));
	pl_rect2.setOutlineThickness(7.f);

	sf::RectangleShape pl_rect3(sf::Vector2f(135.f,85.f));
	pl_rect3.setPosition(1287.5, 325.f);
	pl_rect3.setFillColor(sf::Color::Black);
	pl_rect3.setOutlineColor(sf::Color(140, 20, 252));
	pl_rect3.setOutlineThickness(7.f);

	sf::RectangleShape pl_rect4(sf::Vector2f(135.f,85.f));
	pl_rect4.setPosition(1287.5, 445.f);
	pl_rect4.setFillColor(sf::Color::Black);
	pl_rect4.setOutlineColor(sf::Color(211, 84, 0));
	pl_rect4.setOutlineThickness(7.f);

  sf::Text pl_name1;
	pl_name1.setFont(font3);
	pl_name1.setString(pl0);
	pl_name1.setPosition(1290.f, 92.f);
	pl_name1.setFillColor(sf::Color(30, 130, 76));
	pl_name1.setCharacterSize(27);

	sf::Text pl_name2;
	pl_name2.setFont(font3);
	pl_name2.setString(pl1);
	pl_name2.setPosition(1290.f, 212.f);
	pl_name2.setFillColor(sf::Color(37, 116, 169));
	pl_name2.setCharacterSize(27);

	sf::Text pl_name3;
	pl_name3.setFont(font3);
	pl_name3.setString(pl2);
	pl_name3.setPosition(1290.f, 332.f);
	pl_name3.setFillColor(sf::Color(140, 20, 252));
	pl_name3.setCharacterSize(27);

	sf::Text pl_name4;
	pl_name4.setFont(font3);
	pl_name4.setString(pl3);
	pl_name4.setPosition(1290.f, 452.f);
	pl_name4.setFillColor(sf::Color(211, 84, 0));
	pl_name4.setCharacterSize(27);

	board_win.draw(pl_rect1);
	board_win.draw(pl_rect2);
	board_win.draw(pl_rect3);
	board_win.draw(pl_rect4);

	board_win.draw(pl_name1);
	board_win.draw(pl_name2);
	board_win.draw(pl_name3);
	board_win.draw(pl_name4);
  }
	board_win.display();
}


void disp_icon_i(sf::RenderWindow& board_win, float plx_i, float ply_i, sf::CircleShape& icon_i,player pl[],int sz){
  board_win.clear();
  icon_i.setPosition(sf::Vector2f(plx_i, ply_i));
  make_board(board_win,pl,sz);
}

void disp_player_chan(sf::RenderWindow& board_win, int i, player pl[], int sz){
  board_win.clear();
  chance_i.setOutlineThickness(5.f);
  chance_i.setFillColor(sf::Color::Black);
  if(i==0){chance_i.setOutlineColor(sf::Color(30, 130, 76));}
  else if(i==1){chance_i.setOutlineColor(sf::Color(37, 116, 169));}
  else if(i==2){chance_i.setOutlineColor(sf::Color(140, 20, 252));}
  else if(i==3){chance_i.setOutlineColor(sf::Color(211, 84, 0));}
  chance_i.setPosition(sf::Vector2f(1290.f, 835.f));
  make_board(board_win,pl,sz);
}

void setCoods(sf::Vector2f coods[]){
  int a=0;
  coods[0].x = 1185;
  coods[0].y = 876;
  while (a < 40) {
    while(a < 10){
		if (coods[a].x == 1185) {
			a++;
			coods[a].x = coods[a - 1].x - 110;
			coods[a].y = 876.f;
			continue;
		}
		if (coods[a].x == 339) {
			a++;
			coods[a].x = coods[a - 1].x - 110;
			coods[a].y = 876.f;
		}
		else {
			a++;
			coods[a].x = coods[a - 1].x - 92;
			coods[a].y = 876.f;
		}
	
  }
	//	if (xcoods[j] == 229 && ycoods[j] <= 865 && ycoods[j] >= 149) {
	a = 10;
	while (a < 20) {
		if (coods[a].y == 876) {
			a++;
			coods[a].y = coods[a - 1].y - 105;
			coods[a].x = 229.f;
			continue;
		}
		if (coods[a].y == 155) {
			a++;
			coods[a].y = coods[a - 1].y - 100;
			coods[a].x = 229.f;
		}
		else {
			a++;
			coods[a].y = coods[a - 1].y - 77;
			coods[a].x = 229.f;
		}
	}
	a = 20;
	// 	if (xcoods[j] >= 229 && xcoods[j] <= 1075 && ycoods[j] == 49) {
	while (a < 30) {
		if (coods[a].x == 229) {
			a++;
			coods[a].x = coods[a - 1].x + 110;
			coods[a].y = 55.f;
			continue;
		}
		if (coods[a].x == 1075) {
			a++;
			coods[a].x = coods[a - 1].x + 110;
			coods[a].y = 55.f;
		}
		else {
			a++;
			coods[a].x = coods[a - 1].x + 92;
			coods[a].y = 55.f;
		}
	}
	a = 30;
	// 	if (xcoods[j] == 1185 && ycoods[j] <= 768 && ycoods[j] >= 49) {
	while (a < 40) {
		if (coods[a].y == 55) {
			a++;
			coods[a].y = coods[a - 1].y + 100;
			coods[a].x = 1185.f;
			continue;
		}
		if (coods[a].y == 771) {
			a++;
			coods[a].y = coods[a - 1].y + 105;
			coods[a].x = 1185.f;
		}
		else {
			a++;
			coods[a].y = coods[a - 1].y + 77;
			coods[a].x = 1185.f;
		}
	}
}
}
void setBoughtCoods(sf::Vector2f mainCoods[], sf::Vector2f boughtCoods[]){
  int p=0;
  boughtCoods[0].x=mainCoods[0].x;boughtCoods[0].y=mainCoods[0].y;
  boughtCoods[10].x=mainCoods[10].x;boughtCoods[10].y=mainCoods[10].y;
  boughtCoods[20].x=mainCoods[20].x;boughtCoods[20].y=mainCoods[20].y;
  boughtCoods[30].x=mainCoods[30].x;boughtCoods[30].y=mainCoods[30].y;
  while(p<40){
    if(p>=1 && p<=9){
      boughtCoods[p].x=mainCoods[p].x;
      boughtCoods[p].y=mainCoods[p].y-74.f; 
    }
    if(p>=11 && p<=19){
      boughtCoods[p].x=mainCoods[p].x+79.f;
      boughtCoods[p].y=mainCoods[p].y;      
    }
    if(p>=21 && p<=29){
      boughtCoods[p].x=mainCoods[p].x;
      boughtCoods[p].y=mainCoods[p].y+84;      
    } 
    if(p>=31 && p<=39){
      boughtCoods[p].x=mainCoods[p].x-85;
      boughtCoods[p].y=mainCoods[p].y;      
    }
    p++;
  }
}

void dispBoughtIcon(int iter, int i, sf::Vector2f boughtCoods[], sf::RenderWindow& board_win, int size, player pl[]){
  boughtIcon[iter].setRadius(10.0);
  if(i==0){boughtIcon[iter].setFillColor(sf::Color(30, 130, 76));}
  else if(i==1){boughtIcon[iter].setFillColor(sf::Color(37, 116, 169));}
  else if(i==2){boughtIcon[iter].setFillColor(sf::Color(140, 20, 252));}
  else if(i==3){boughtIcon[iter].setFillColor(sf::Color(211, 84, 0));}
  else {boughtIcon[iter].setFillColor(sf::Color::Black);}
  boughtIcon[iter].setPosition(boughtCoods[iter].x, boughtCoods[iter].y);
  if(iter==24){boughtIcon[24].setPosition(619, 139);}
  board_win.clear();
  make_board(board_win, pl, size);
}

void dispMortgageIcon(int iter,int player_chance, sf::Vector2f boughtCoods[], sf::RenderWindow& board_win, int size, player pl[]) {
	if (font0.loadFromFile("../Fonts/Avara.otf") == false)
        	std::cout << "Loading failed" << std::endl;
	text_m[iter].setFont(font0);
	text_m[iter].setString("M");
	if(player_chance==0){text_m[iter].setFillColor(sf::Color(30, 130, 76));}
  else if(player_chance==1){text_m[iter].setFillColor(sf::Color(37, 116, 169));}
  else if(player_chance==2){text_m[iter].setFillColor(sf::Color(140, 20, 252));}
  else if(player_chance==3){text_m[iter].setFillColor(sf::Color(211, 84, 0));}
	text_m[iter].setStyle(sf::Text::Bold);
	text_m[iter].setPosition(boughtCoods[iter].x, boughtCoods[iter].y);
	board_win.clear();
	make_board(board_win, pl, size);
}

void disp_house(int iter,int n,sf::Vector2f Coods[], sf::RenderWindow& board_win, int size, player pl[]){ 
  if(n>0)
  {
	if(house.loadFromFile("../Images/house.png") == false)
  		std::cout << "Loading failed" << std::endl;
	house_sprite[iter].setScale(sf::Vector2f(0.14,0.15));
	house_sprite[iter].setPosition(sf::Vector2f(Coods[iter].x-37,Coods[iter].y-20));
	house_sprite[iter].setTexture(house);

	
    	if (font0.loadFromFile("../Fonts/Avara.otf") == false)
        	std::cout << "Loading failed" << std::endl;

	num[iter].setFont(font0);
	num[iter].setString("X"+std::to_string(n));
	num[iter].setFillColor(sf::Color::Blue);
	num[iter].setCharacterSize(25);
	num[iter].setStyle(sf::Text::Bold);
	num[iter].setPosition(sf::Vector2f(Coods[iter].x-3, Coods[iter].y+14));
  }
  else
  {
	  num[iter].setFillColor(sf::Color(255,0,0,0));
  }
  board_win.clear();
  make_board(board_win, pl, size);
}
