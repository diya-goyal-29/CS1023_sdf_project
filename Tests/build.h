#ifndef BUILD_H
#define BUILD_H
#include<gtest/gtest.h>
#include"../Code/players.h"

/**
 * @brief This build function acts same as the actual build function except the graphical part.
 * 
 * @param p player who want to build houses in his property.
 * @param property_num index of the property.
 * @param num_of_houses number of houses the player want to build.
 */
void build(player& p,int property_num,int num_of_houses);


#endif