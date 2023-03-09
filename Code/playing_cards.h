#ifndef PLAYING_CARDS_H
#define PLAYING_CARDS_H
#include"players.h"


/**
 * @brief playing_cards is function which displays the playing card in a new window with an option to buy.
 * 
 * @param num index of card in places array
 * @param pl player who lands on this property
 * @param i index of the player
 * @param plbuy a boolen variable which becomes true when player buys that property.
 */
void playing_cards(int num,player& pl,int i,bool& plbuy);

#endif // !PLAYING_CARDS_H