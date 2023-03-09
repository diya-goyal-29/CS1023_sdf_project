#ifndef MORTGAGE_OR_UNMORTGAGE_H
#define	MORTGAGE_OR_UNMORTGAGE_H
#include"players.h"
#include"BoardCode.h"
#include"properties.h"
#include<SFML/Graphics.hpp>

/**
 * @brief print_places function prints the name of the place of given index.
 * 
 * @param num index of place
 * @param text text which has place name as string.
 */
void print_places(int *num, sf::Text &text);

/**
 * @brief creates id from playerinput.
 * 
 * @param playerInput text enetred by player.
 * @return int returns id of player.
 */
int set_id(sf::Text &playerInput);

/**
 * @brief check_id function checks whether the owner of the property is the given player or not.
 * 
 * @param id index of the property
 * @param pl player
 * @param is_fun_mort 
 * @return true returns true if the player owns that property
 */
bool check_id(int id, player pl, bool is_fun_mort);

/**
 * @brief change_status function changes the status  from ownership to mortgage
 * 
 * @param id status
 */
void change_status(int *id);

/**
 * @brief dispMortgageIcon function displays the text "M" on bought icon
 * 
 * @param iter index of the place.
 * @param boughtCoods array of coordinates of bought icon
 * @param board_win main game window
 * @param text text ("M") which is written on the icon
 * @param size number of players
 * @param pl array of players
 */
void dispMortgageIcon(int iter, sf::Vector2f boughtCoods[], sf::RenderWindow& board_win, sf::Text &text, int size, player pl[]);

/**
 * @brief mortgage function helps the player to mortgage his property.
 * 
 * @param pl array of players.
 * @param player_chance index of player.
 * @param board_win main game window.
 * @param size number of players.
 */
void mortgage(player pl[], int player_chance, sf::RenderWindow& board_win, int size);

/**
 * @brief unmortgage function helps the player to unmortgage his property.
 * 
 * @param pl array of players.
 * @param player_chance index of player.
 * @param board_win main game window.
 * @param size number of players.
 */
void unmortgage(player pl[], int player_chance, sf::RenderWindow& board_win, int size);

#endif // !MORTGAGE_OR_UNMORTGAGE_H

