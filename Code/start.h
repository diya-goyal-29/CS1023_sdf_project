#ifndef START_H
#define START_H
#include<iostream>
#include<SFML/Graphics.hpp>
/**
 * @brief input is a function which fills the input box with given string at given position
 * 
 * @param window It's the window which contains the input box.
 * @param event It's the event happenening in window.
 * @param box It's the rectangular box in which input is given.
 * @param str It's the string which is given as input.
 * @param text It's the text which has input string str.
 * @param font It' the font of input string.
 * @param x It's the x coordinate of text in the window.
 * @param y It's the y coordinate of text in the window.
 * @param sel It's a boolean variable which tells whether the mouse button is pressed or not.
 */
void input(sf::Window &window, sf::Event &event, sf::RectangleShape box, std::string &str, sf::Text &text, sf::Font *font, int x, int y, bool sel);

/**
 * @brief Creates a box object with given parameters.
 * 
 * @param box It's the outline shape of the object.
 * @param texture It's the texture of the object.
 * @param scaleX It's the x scale factor of the object.
 * @param scaleY It's the x scale factor of the object.
 * @param x It's the x coordinate of object in the window.
 * @param y It's the y coordinate of object in the window.
 * @param outColor It's the outline colour of the object.
 */
void setBox(sf::RectangleShape &box, sf::Texture *texture, float scaleX, float scaleY, int x, int y, sf::Color outColor);

/**
 * @brief Creates a box object with given parameters.
 * 
 * @param box It's the outline shape of the object.
 * @param x It's the x coordinate of object in the window.
 * @param y It's the y coordinate of object in the window.
 * @param fillColor It's the filled colour of the object.
 * @param outColor It's the outline colour of the object.
 * @param t It's the outline thickness of the object.
 */
void setBox(sf::RectangleShape &box, int x, int y, sf::Color fillColor, sf::Color outColor, int t);

/**
 * @brief Set the Text object
 * 
 * @param text It's the text to be set.
 * @param font It's the font of text.
 * @param str It's the string of text.
 * @param x It's the x coordinate of text in the window.
 * @param y It's the y coordinate of text in the window.
 * @param size It's the size of text in the window.
 * @param color It's the colour of text in the window.
 */
void setText(sf::Text &text, sf::Font *font, std::string str, int x, int y, int size, sf::Color color);

/**
 * @brief Set the Sprite object
 * 
 * @param sprite It's the sprite to be set.
 * @param scaleX It's the x scale factor of the object.
 * @param scaleY It's the y scale factor of the object.
 * @param x It's the x coordinate of sprite in the window.
 * @param y It's the y coordinate of sprite in the window.
 * @param texture It's the texture of the sprite.
 */
void setSprite(sf::Sprite &sprite, float scaleX, float scaleY, int x, int y, sf::Texture *texture);

/**
 * @brief msgDisplay function displays the given string in a small window.
 * 
 * @param str It's the string to be displayed.
 */
void msgDisplay(std::string str);


typedef struct 
{
    int num_players;
    std::string Name[4];
} Inputs;

/**
 * @brief Run function provides a window for player to give all the input required and later it directs him/ her to main game window.
 * 
 * @param run It's a boolean variable which becomes true when player hits start.
 * @return returns a struct which has all input given by players ( players' name, number of players).
 */
Inputs Run(bool& run);


#endif