#ifndef BUILD_AND_SELL_H
#define BUILD_AND_SELL_H
#include <array>
#include <string>
#include <SFML/Graphics.hpp>
#include"players.h"
typedef struct 
{
    int p;
    int n;
} pair_t;

enum class sell_or_buy {SELL,BUY};

/**
 * @brief selection function helps the player to build or sell the selcted number of houses on selected property.
 * 
 * @param sell_or_buy enum class which tells whether the window is sell or build.
 * @param pl player who is playing now. 
 * @param p a struct which has property number and number of houses as variables.
 * @param sz number of properties owned by player.
 * @param window window displayed for selection process.
 * @param rect1 rectangular box which contains properties names.
 * @param rect2 rectangular box which contains number from 1 to 5 (number of houses).
 * @param confirm_r recatngular shaped button to confirm.
 */
void selection(sell_or_buy,player pl,pair_t& p,int sz,sf::RenderWindow &window, std::array<sf::RectangleShape, 40> &rect1, std::array<sf::RectangleShape, 5> &rect2,sf::RectangleShape& confirm_r);

/**
 * @brief build function allows the player to build houses on his property if he has all properties in a particular colony.
 * 
 * @param pl player array
 * @param index index of player
 * @param main_window main board window
 * @param Coods coordinates of center of the property.
 * @param size number of players.
 */
void build(player pl[],int index, sf::RenderWindow &main_window,sf::Vector2f Coods[],int size);

/**
 * @brief sell function allows the player to sell houses of his property.
 * 
 * @param pl player array
 * @param index index of player
 * @param main_window main board window
 * @param Coods coordinates of center of the property.
 * @param size number of players.
 */
void sell(player pl[],int index, sf::RenderWindow &main_window,sf::Vector2f Coods[],int size);
#endif