#ifndef JAIL_H
#define JAIL_H

#include<SFML/Graphics.hpp>
#include"players.h"
#include"diceRoller.h"

/**
 * @brief jail function executes the code when player gets a "Go to Jail" card.
 * 
 * @param pl player array
 * @param player_chance index of player
 * @return roll_die returns the number on die when player is at jail.
 */
roll_die jail(player pl[], int *player_chance, int *size);
#endif // !JAIL_H
