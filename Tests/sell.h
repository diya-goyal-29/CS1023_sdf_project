#ifndef SELL_H
#define SELL_H
#include<gtest/gtest.h>
#include"../Code/players.h"
#include"../Code/players.h"

/**
 * @brief This sell function acts same as actual sell function except the graphical part..
 * 
 * @param p player who want to sell houses in his property.
 * @param property_num index of the property.
 * @param num_of_houses number of houses the player want to sell.
 */
void sell(player& p,int property_num,int num_of_houses);


#endif