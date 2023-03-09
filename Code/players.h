#ifndef PLAYERS_H
#define PLAYERS_H
#include<SFML/Graphics.hpp>

/**
 * @brief player is player class which has all the members a player has.
 * 
 */
class player {
public:
	std::string playerName; // name of the player
	int playerProps[40]; // array of index of properties owned by player.
	int numbProps = 0; // number of properties owned by player.
	int playerHouses[40]={0};//playerhouses[i] refers to the number of houses the player has in playerprops[i]
	int money; // total money the player has.
	int playerMortProps[40] = { 0 }; // array of index of properties mortgaged by player.
	int numbMortProps = 0; //number of properties mortgaged by player.
	int playerValue = 0; // the sum which includes player money and cost of properties , houses owned by player.This is used to decide winner.
	bool is_jail = false; // a boolean variable which tells whether the player is in jail or not.
	int in_jail = 0; // number of chances the player have to throw a double to get out of jail.
	sf::CircleShape icon; // icon of the player.
	bool get_out_of_jail=true; // a boolean variable which tells whether the player can get out of jail or not.
	int count[9] = { 0 }; //array of number of properties owned by player in a colony
	const int max_count[8] = { 2,3,3,3,3,3,3,2 }; //array of maximum number of properties  in a colony
};
#endif // !PLAYERS_H
