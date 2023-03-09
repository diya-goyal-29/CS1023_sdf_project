#ifndef MORTGAGE_H
#define MORTGAGE_H
#include<gtest/gtest.h>
#include"../Code/players.h"
#include"../Code/properties.h"
#include"../Code/cards.h"

/**
 * @brief This mortgage function acts same as actual mortgage function except the graphical part.
 * 
 * @param pl player
 * @param playerText property number entered by player.
 */
void mortgage(player& pl,sf::Text playerText) ;

/**
 * @brief This unmortgage function acts same as actual unmortgage function except the graphical part.
 * 
 * @param pl player
 * @param playerText property number entered by player.
 */
void unmortgage(player& pl,sf::Text playerText) ;
#endif