#include"start.h"
#include"BoardCode.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
sf::Font font;

void input(sf::Window &window, sf::Event &event, sf::RectangleShape box, std::string &str, sf::Text &text, sf::Font *font, int x, int y, bool sel)
{
    float mouseX = sf::Mouse::getPosition(window).x;
    float mouseY = sf::Mouse::getPosition(window).y;

    float boxX = box.getPosition().x;
    float boxY = box.getPosition().y;

    float boxWidth = box.getPosition().x + box.getSize().x;
    float boxHeight = box.getPosition().y + box.getSize().y;

    if ((mouseX < boxWidth) && (mouseX > boxX) && (mouseY < boxHeight) && (mouseY > boxY))
    {
        if(sel)
        {
            if (event.text.unicode < 128)
            {
                if (event.text.unicode == '\b' && str != "\0")
                    str.erase(str.size() - 1, sizeof(char32_t));
                else
                {
                    if(str.size()<=11)
                        str += static_cast<char>(event.text.unicode);
                    else
                        msgDisplay("Name cannot exceed 11 charecters");
                }
            }
            text.setString(str + "_");
        }
        else
            text.setString(str);

        text.setFont(*font);
        text.setCharacterSize(30);
        text.setFillColor(sf::Color(255, 255, 255));
        text.setPosition(x, y);
    }
}


void setBox(sf::RectangleShape &box, sf::Texture *texture, float scaleX, float scaleY, int x, int y, sf::Color outColor)
{
    box.setTexture(texture);
    box.setScale(sf::Vector2f(scaleX, scaleY));
    box.setPosition(sf::Vector2f(x, y));
    box.setOutlineColor(outColor);
}

void setBox(sf::RectangleShape &box, int x, int y, sf::Color fillColor, sf::Color outColor, int t)
{
    box.setPosition(x, y);
    box.setFillColor(fillColor);
    box.setOutlineColor(outColor);
    box.setOutlineThickness(t);
}

void setText(sf::Text &text, sf::Font *font, std::string str, int x, int y, int size, sf::Color color)
{
    text.setFont(*font);
    text.setString(str);
    text.setPosition(x, y);
    text.setCharacterSize(size);
    text.setFillColor(color);
}

void setSprite(sf::Sprite &sprite, float scaleX, float scaleY, int x, int y, sf::Texture *texture)
{
    sprite.setScale(sf::Vector2f(scaleX, scaleY));
    sprite.setPosition(sf::Vector2f(x, y));
    sprite.setTexture(*texture);
}

void msgDisplay(std::string str)
{
    sf::RenderWindow window(sf::VideoMode(600, 100), "Messasge", sf::Style::Close);
    window.clear();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            sf::Text msg;
            
            if (font.loadFromFile("../Fonts/Avara.otf") == false)
                std::cout << "Loading failed" << std::endl;

            setText(msg, &font, str, 10, 10, 30, sf::Color(255, 255, 255));

            window.draw(msg);
            window.display();
            
        }
    }
}


//#################### Start of run function ################

Inputs Run(bool& run)
{
    Inputs ip; 
    ip.num_players=0;
    sf::RenderWindow window1(sf::VideoMode(800, 900), "Monopoly", sf::Style::Close);

    sf::Texture next;
    if(next.loadFromFile("../Images/next_free.png") == false)
        std::cout << "Loading failed" << std::endl;

   
    if (font.loadFromFile("../Fonts/Avara.otf") == false)
        std::cout << "Loading failed" << std::endl;

    sf::Sprite button1;
    setSprite(button1, 0.4, 0.3, 530, 750, &next);

    sf::Texture Banner;
    if (Banner.loadFromFile("../Images/banner.png") == false)
        std::cout << "Loading failed" << std::endl;

    sf::Sprite banner;
    setSprite(banner, 1.5, 0.8, 18, -20, &Banner);

    sf::Texture two_players, three_players, four_players;
    if (two_players.loadFromFile("../Images/2_players_free.png") == false)
        std::cout << "Loading failed" << std::endl;

    if (three_players.loadFromFile("../Images/3_players.png") == false)
        std::cout << "Loading failed" << std::endl;

    if (four_players.loadFromFile("../Images/4_players_free.png") == false)
        std::cout << "Loading failed" << std::endl;

    sf::RectangleShape two(sf::Vector2f(600, 700));
    sf::RectangleShape three(sf::Vector2f(450, 550));
    sf::RectangleShape four(sf::Vector2f(450, 550));

    setBox(two, &two_players, 0.3, 0.3, 30, 410, sf::Color(0, 0, 0));
    setBox(three, &three_players, 0.5, 0.4, 280, 410, sf::Color(0, 0, 0));
    setBox(four, &four_players, 0.55, 0.4, 540, 410, sf::Color(0, 0, 0));

    sf::Text two_text, three_text, four_text;
    setText(two_text, &font, "Two players", 50, 640, 25, sf::Color(0, 255, 0));
    setText(three_text, &font, "Three players", 320, 650, 25, sf::Color(0, 255, 0));
    setText(four_text, &font, "Four players", 600, 650, 25, sf::Color(0, 255, 0));

    window1.setFramerateLimit(60);
    while (window1.isOpen())
    {
        sf::Text text0;
        setText(text0, &font, "NUMBER OF PLAYERS", 20, 350, 30, sf::Color(0, 255, 0));

        sf::Event event1;
        while (window1.pollEvent(event1))
        {
            if (event1.type == sf::Event::Closed)
                window1.close();

            if (event1.type == sf::Event::MouseButtonPressed)
            {
                //############ Selection of number of players

                if (two.getGlobalBounds().contains(sf::Mouse::getPosition(window1).x, sf::Mouse::getPosition(window1).y))
                {
                    two.setOutlineColor(sf::Color(255, 0, 0));
                    two.setOutlineThickness(14);
                    three.setOutlineColor(sf::Color(0, 0, 0));
                    four.setOutlineColor(sf::Color(0, 0, 0));
                }

                if (three.getGlobalBounds().contains(sf::Mouse::getPosition(window1).x, sf::Mouse::getPosition(window1).y))
                {
                    three.setOutlineColor(sf::Color(255, 0, 0));
                    three.setOutlineThickness(10);
                    two.setOutlineColor(sf::Color(0, 0, 0));
                    four.setOutlineColor(sf::Color(0, 0, 0));
                }

                if (four.getGlobalBounds().contains(sf::Mouse::getPosition(window1).x, sf::Mouse::getPosition(window1).y))
                {
                    four.setOutlineColor(sf::Color(255, 0, 0));
                    four.setOutlineThickness(10);
                    two.setOutlineColor(sf::Color(0, 0, 0));
                    three.setOutlineColor(sf::Color(0, 0, 0));
                }


                
                if (button1.getGlobalBounds().contains(sf::Mouse::getPosition(window1).x, sf::Mouse::getPosition(window1).y))
                {
                    if (two.getOutlineColor() == sf::Color(0, 0, 0) && four.getOutlineColor() == sf::Color(0, 0, 0) && three.getOutlineColor() == sf::Color(0, 0, 0))
                        msgDisplay("Select number of players");

                    else ///################## Opening the next window ################
                    {
                        std::string str1, str2, str3, str4;

                        sf::Text name1, name2, name3, name4;
                        sf::RenderWindow window3(sf::VideoMode(600, 600), "Monopoly", sf::Style::Close);
                        window1.close();
                        while (window3.isOpen())
                        {

                            sf::Text text1, text2, text3, text4;

                            sf::RectangleShape box1(sf::Vector2f(310, 50)), box2(sf::Vector2f(310, 50)),
                                box3(sf::Vector2f(310, 50)), box4(sf::Vector2f(310, 50));

                            setText(text1, &font, "Player 1  : ", 20, 50, 30, sf::Color(0, 255, 0));
                            setBox(box1, 180, 50, sf::Color(0, 0, 0), sf::Color(0, 255, 0), 2);

                            setText(text2, &font, "Player 2 : ", 20, 150, 30, sf::Color(0, 255, 0));
                            setBox(box2, 180, 150, sf::Color(0, 0, 0), sf::Color(0, 255, 0), 2);

                            if (three.getOutlineColor() == sf::Color(255, 0, 0))
                            {
                                setText(text3, &font, "Player 3 : ", 20, 250, 30, sf::Color(0, 255, 0));
                                setBox(box3, 180, 250, sf::Color(0, 0, 0), sf::Color(0, 255, 0), 2);
                            }
                            if (four.getOutlineColor() == sf::Color(255, 0, 0))
                            {
                                setText(text3, &font, "Player 3 : ", 20, 250, 30, sf::Color(0, 255, 0));
                                setBox(box3, 180, 250, sf::Color(0, 0, 0), sf::Color(0, 255, 0), 2);
                                setText(text4, &font, "Player 4 : ", 20, 350, 30, sf::Color(0, 255, 0));
                                setBox(box4, 180, 350, sf::Color(0, 0, 0), sf::Color(0, 255, 0), 2);
                            }

                            sf::Texture start;
                            if (start.loadFromFile("../Images/start.png") == false)
                                std::cout << "Loading failed" << std::endl;
                            
                            sf::CircleShape circle(250);
                            circle.setFillColor(sf::Color(0,255,0));
                            circle.setPosition(140,440);
                            circle.setScale(0.6,0.25);
                            circle.setOutlineColor(sf::Color::White);
                            circle.setOutlineThickness(10);
                            

                            // sf::Text start;
                            // start.setString("START");
                            // start.setFont(font);
                            // start.setPosition(200,480);
                            // start.setCharacterSize(50);
                            // start.setFillColor(sf::Color::Black);
                            sf::Sprite Start;
                            setSprite(Start, 0.55, 0.21, 140, 440, &start);

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
                                    window3.close();
                                if (event3.type == sf::Event::TextEntered)
                                {
                                    //#################### Taking input name from user ############

                                    input(window3, event3, box1, str1, name1, &font, 190, 55, sel);
                                    input(window3, event3, box2, str2, name2, &font, 190, 155, sel);

                                    if (three.getOutlineColor() == sf::Color(255, 0, 0))
                                    {
                                        input(window3, event3, box3, str3, name3, &font, 190, 255, sel);
                                    }

                                    if (four.getOutlineColor() == sf::Color(255, 0, 0))
                                    {
                                        input(window3, event3, box3, str3, name3, &font, 190, 255, sel);
                                        input(window3, event3, box4, str4, name4, &font, 190, 355, sel);
                                    }
                                }

                                if (event3.type == sf::Event::MouseButtonPressed)
                                {

                                    if (circle.getGlobalBounds().contains(sf::Mouse::getPosition(window3).x, sf::Mouse::getPosition(window3).y))
                                    {
                                        int flag=0;
                                        if(two.getOutlineColor()==sf::Color(255,0,0) && ((str1 == "\0") || (str1 == "_") || (str2 == "\0") || (str2 == "_") ))
                                        {
                                            msgDisplay("Enter all players' names");
                                            flag=1;   
                                        }
                                        if(three.getOutlineColor()==sf::Color(255,0,0) && ((str1 == "\0") || (str1 == "_") || (str2 == "\0") || (str2 == "_")|| (str3 == "\0") || (str3 == "_") ))
                                        {
                                            msgDisplay("Enter all players' names");
                                            flag=1;   
                                        }
                                         if(four.getOutlineColor()==sf::Color(255,0,0) && ((str1 == "\0") || (str1 == "_") || (str2 == "\0") || (str2 == "_") || (str3 == "\0") || (str3 == "_") || (str4=="\0") || (str4=="_")))
                                        {
                                            msgDisplay("Enter all players' names");
                                            flag=1;   
                                        }
                                        if(flag==0)
                                        {
                                            window3.close();
                                            run=1;

                                            //########## Setting the return value ###############

                                            if(two.getOutlineColor() == sf::Color(255, 0, 0))
                                            {
                                                ip.num_players=2;
                                                ip.Name[0]=str1;
                                                ip.Name[1]=str2;
                                            } 
                                            if(three.getOutlineColor() == sf::Color(255, 0, 0))
                                            {
                                                ip.num_players=3;
                                                ip.Name[0]=str1;
                                                ip.Name[1]=str2;
                                                ip.Name[2]=str3;
                                            } 
                                            if(four.getOutlineColor() == sf::Color(255, 0, 0))
                                            {
                                                ip.num_players=4;
                                                ip.Name[0]=str1;
                                                ip.Name[1]=str2;
                                                ip.Name[2]=str3;
                                                ip.Name[3]=str4;
                                            } 
                                        }
                                    }
                                }
                                window3.clear();
                                // window3.draw(circle);
                                
                                window3.draw(Start);
                                window3.draw(box1);
                                window3.draw(text1);
                                window3.draw(box2);
                                window3.draw(text2);
                                window3.draw(name1);
                                window3.draw(name2);
                                if (three.getOutlineColor() == sf::Color(255, 0, 0))
                                {
                                    window3.draw(box3);
                                    window3.draw(text3);
                                    window3.draw(name3);
                                }
                                if (four.getOutlineColor() == sf::Color(255, 0, 0))
                                {
                                    window3.draw(box3);
                                    window3.draw(text3);

                                    window3.draw(box4);
                                    window3.draw(text4);
                                    window3.draw(name3);
                                    window3.draw(name4);
                                }

                                window3.display();
                                //window3.clear();
                            }
                        }
                    }
                }
            }

            window1.draw(button1);
            window1.draw(text0);
            window1.draw(two_text);
            window1.draw(three_text);
            window1.draw(four_text);
            window1.draw(banner);
            window1.draw(two);
            window1.draw(three);
            window1.draw(four);

            window1.display();
            window1.clear();
        }
    }
    return ip;
}
