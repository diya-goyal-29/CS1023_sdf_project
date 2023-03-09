#ifndef DICEROLLER_H
#define DICEROLLER_H

struct roll_die_t
{
	int dice_1;
	int dice_2;
}typedef roll_die;

/**
 * @brief rollDice function creates a random randow and displays that face of dice in a window.
 * 
 * @return roll_die returns the struct which contain the number shown on each dice.
 */
roll_die rollDice();




#endif