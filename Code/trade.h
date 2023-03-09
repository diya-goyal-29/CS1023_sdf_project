#ifndef TRADE_H
#define TRADE_H
#include<vector>
#include<algorithm>
#include<iterator>
#include<array>
#include"players.h"
#include"properties.h"
#include"start.h"
#include"mortgage_or_unmortgage.h"

void removeIcon(int iter, sf::Vector2f boughtCoods[], sf::RenderWindow& board_win, int size, player pl[]);

void trade(player pl[], int player_chance, int size, sf::Vector2f boughtCoods[], sf::RenderWindow& board_win);

#endif
