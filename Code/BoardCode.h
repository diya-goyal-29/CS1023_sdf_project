#ifndef BOARDCODE_H
#define BOARDCODE_H
#include<SFML/Graphics.hpp>
#include"players.h"
/**
 * @brief make_board function creates the monopoly board with player icons at start position on it.
 * 
 * @param board_win window on which board is displayed.
 * @param pl array of players.
 * @param sz number of players.
 */
void make_board(sf::RenderWindow& board_win,player pl[],int sz);

/**
 * @brief 
 * 
 * @param board_win disp_icon_i function displays icons on given position of board.
 * @param plx_i x coordinate of player icon.
 * @param ply_i y coordinate of player icon.
 * @param icon_i player icon.
 * @param pl array of all players.
 * @param sz number of players.
 */
void disp_icon_i(sf::RenderWindow& board_win, float plx_i, float ply_i, sf::CircleShape& icon_i,player pl[],int sz);

/**
 * @brief Sets the given array with the coordinates of center of square of places.
 * 
 * @param coods array of vector coordinates.
 */
void setCoods(sf::Vector2f coods[]);

/**
 * @brief Sets the given array with the coordinates of top of square of places.
 * 
 * @param mainCoods coordinates of center of square of places.
 * @param boughtCoods coordinates of top of square of places
 */
void setBoughtCoods(sf::Vector2f mainCoods[], sf::Vector2f boughtCoods[]);

/**
 * @brief pl_name_mon function displays the players' name and money on main board window.
 * 
 * @param board_win main board window.
 * @param size number of players.
 * @param pl array of players.
 */
void pl_name_mon(sf::RenderWindow& board_win, int size, player pl[]);

/**
 * @brief dispBoughtIcon function displays bought icon of given player at given property.
 * 
 * @param iter index of the property.
 * @param i index of player.
 * @param boughtCoods coordinates at which bought icons to be placed.
 * @param board_win main board window.
 * @param size number of players.
 * @param pl array of players.
 */
void dispBoughtIcon(int iter, int i, sf::Vector2f boughtCoods[], sf::RenderWindow& board_win, int size, player pl[]);

/**
 * @brief dispMortgageIcon function displays morgage icon of given player at given property.
 * 
 * @param iter index of the property.
 * @param boughtCoods coordinates at which bought icons to be placed.
 * @param board_win main board window.
 * @param size number of players.
 * @param pl array of players.
 */
void dispMortgageIcon(int iter, int player_chance, sf::Vector2f boughtCoods[], sf::RenderWindow& board_win, int size, player pl[]);

/**
 * @brief disp_house function displays house and its multipilicity at given property.
 * 
 * @param iter index of the property.
 * @param n number of houses.
 * @param Coods coordinates at which houses to be placed.
 * @param board_win main board window.
 * @param size number of players.
 * @param pl array of players. 
 */
void disp_house(int iter,int n, sf::Vector2f Coods[], sf::RenderWindow& board_win, int size, player pl[]);

void disp_player_chan(sf::RenderWindow& board_win, int i, player pl[], int sz);

extern sf::RectangleShape rectangle1b;
extern sf::Text text1b;
extern sf::RectangleShape rectangle2b;
extern sf::Text text2b;
extern sf::RectangleShape rectangle3b;
extern sf::Text text3b;
extern sf::RectangleShape rectangle4b;
extern sf::Text text4b;
extern sf::RectangleShape rectangle5b;
extern sf::Text text5b;
extern sf::RectangleShape rectangle6b;
extern sf::Text text6b;
#endif

