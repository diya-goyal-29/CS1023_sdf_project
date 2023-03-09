#ifndef PROPERTIES_H
#define PROPERTIES_H
#include<array>
#include<vector>
#include<string>

extern std::array<std::string, 40> places;
extern std::vector<std::vector<int>> group;
extern int rent[6][40];
extern int house_cost[40][2];
extern int prop_cost[40];
extern int owners[40] ;
extern int houses[40];

/**
 * @brief Find_group function finds the group to which the given property belongs.
 * 
 * @param i index of the property.
 * @return int returns the group number of the property.
 */
int Find_group(int i);

#endif