#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <array>
#include <SFML/Graphics.hpp>
#include "start.h"
#include "diceRoller.h"
#include "BoardCode.h"
#include "community_chest.h"
#include "playing_cards.h"
#include "chance.h"
#include"build_and_sell.h"
#include"properties.h"
#include"cards.h"
#include"jail.h"
#include"mortgage_or_unmortgage.h"
#include"trade.h"

/**
 * @brief Board is a class which creates the main window of the game. This class is a singleton class.
 * 
 */
class Board
{
  Board()
  {
    window.create(sf::VideoMode(1440, 960), "Monopoly");
  }
  Board(const Board &) = delete;
  void operator=(Board &) = delete;

public:
  sf::RenderWindow window;
  /**
   * @brief Get the Instance pointer of board.
   * 
   * @return Board* returns pointer to instance object.
   */
  static Board *getInstance()
  {
    static Board *instance;
    if (instance == nullptr)
      instance = new Board();
    return instance;
  }
};

/**
 * @brief game_end function check whether the game should end or not. It 
 * calculates each player's total money and checks whether it's less than zero and 
 * all his/ her properties are mortgaged or not. If this happens then the game ends.
 * 
 * @param pl array of players.
 * @param size_inp number of players.
 * @return true if the game should end.
 */
bool game_end(player pl[], int size_inp){
  for(int y=0; y<size_inp; y++){
    if(pl[y].money<=0 && pl[y].numbProps==pl[y].numbMortProps){
        return true;
    }
  }
  return false;
}

/**
 * @brief dec_win function will decide the winner from the values of players.
 * 
 * @param pl array of players.
 * @param size_input number of players.
 * @return player returns the winner index.
 */
int dec_win(player pl[], int size_input){
  int max_index=0;
  for(int w=0; w<size_input; w++){
    pl[w].playerValue+=pl[w].money;
    if(pl[w].playerValue>=pl[max_index].playerValue){
      max_index=w;
    }
  }
return max_index;
}

/**
 * @brief disp_win function displays the winner in a new window. It finds the winner using
 * dec_win function and displays his name in a ne window.
 * 
 * @param pl array of players.
 * @param size_ipu number of players.
 */
void disp_win(player pl[], int size_ipu){
  int win_index=dec_win(pl, size_ipu);
  
  sf::RenderWindow window_win(sf::VideoMode(1012, 467), "WINNER");
	sf::Font font;
	if (!font.loadFromFile("../Fonts/Champagne & Limousines.ttf"))
	{
		std::cout << "Loading Error" << std::endl;
	}
  sf::Font font2;
	if (!font2.loadFromFile("../Fonts/futur.ttf"))
	{
		std::cout << "Loading Error" << std::endl;
	}

	sf::Texture win_text;
	if (!win_text.loadFromFile("../Images/Winner.png")) {
		std::cout<<"Loading Failed"<<std::endl;
	}
	sf::Sprite spriteWin;
	spriteWin.setTexture(win_text);
	spriteWin.setScale(1.f, 1.f);
	spriteWin.setPosition(sf::Vector2f(0.f, 0.f));

  sf::Text text1;
	text1.setFont(font2);
	text1.setFillColor(sf::Color(255, 20, 147));
  text1.setString("WINNER");
	text1.setPosition(330, 100);
  text1.setCharacterSize(75);
	text1.setStyle(sf::Text::Bold | sf::Text::Underlined);

	sf::Text text2;
	text2.setFont(font);
	text2.setPosition(300, 120);
	text2.setFillColor(sf::Color(138, 43, 226)); 
	text2.setPosition(330, 250);
  text2.setCharacterSize(60);
	text2.setStyle(sf::Text::Bold);
  text2.setString(pl[win_index].playerName);

  	while (window_win.isOpen()) {

		sf::Event event;
		while (window_win.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window_win.close();
			}

		}
		
		window_win.clear();
    window_win.draw(spriteWin);    
    window_win.draw(text1);
    window_win.draw(text2);
		window_win.display();
		}
}


sf::RectangleShape rectangle1b;
sf::Text text1b;
sf::RectangleShape rectangle2b;
sf::Text text2b;
sf::RectangleShape rectangle3b;
sf::Text text3b;
sf::RectangleShape rectangle4b;
sf::Text text4b;
sf::RectangleShape rectangle5b;
sf::Text text5b;
sf::RectangleShape rectangle6b;
sf::Text text6b;

int main()
{
  bool run = 0;
  Inputs ip;
  ip = Run(run);
  int size = ip.num_players;
  player pl[size];
  for(int e=0; e<size; e++){
    pl[e].playerName=ip.Name[e];
  }
  if (size == 2)
  {
    pl[0].icon.setFillColor(sf::Color(30, 130, 76));
    pl[0].icon.setRadius(16.0);
    pl[1].icon.setFillColor(sf::Color(37, 116, 169));
    pl[1].icon.setRadius(16.0);
  }
  if (size == 3)
  {
    pl[0].icon.setFillColor(sf::Color(30, 130, 76));
    pl[0].icon.setRadius(16.0);
    pl[1].icon.setFillColor(sf::Color(37, 116, 169));
    pl[1].icon.setRadius(16.0);
    pl[2].icon.setFillColor(sf::Color(140, 20, 252));
    pl[2].icon.setRadius(16.0);
  }
  if (size == 4)
  {
    pl[0].icon.setFillColor(sf::Color(30, 130, 76));
    pl[0].icon.setRadius(16.0);
    pl[1].icon.setFillColor(sf::Color(37, 116, 169));
    pl[1].icon.setRadius(16.0);
    pl[2].icon.setFillColor(sf::Color(140, 20, 252));
    pl[2].icon.setRadius(16.0);
    pl[3].icon.setFillColor(sf::Color(211, 84, 0));
    pl[3].icon.setRadius(16.0);
  }

  sf::Vector2f coods[40];
  sf::Vector2f boughtCoods[40];

  setCoods(coods);
  setBoughtCoods(coods, boughtCoods);

  float plx[size], ply[size];
  

  
  //	intitialisation
  for (int q = 0; q < 4; q++)
  {
    plx[q] = coods[0].x;
    ply[q] = coods[0].y;
    (pl[q].icon).setPosition(coods[0]);

  }

  int numrot[size];

  card chanceCard[13];
  card comChCard[14];

  chanceCard[2].setType(cardType::MOVE);
  chanceCard[2].setPosition(39);

  chanceCard[3].setType(cardType::MOVE);
  chanceCard[3].setPosition(0);

  chanceCard[4].setType(cardType::MOVE);
  chanceCard[4].setPosition(24);

  chanceCard[5].setType(cardType::MONEY);
  chanceCard[5].setMoney(-35);

  chanceCard[6].setType(cardType::MONEY);
  chanceCard[6].setMoney(50);

  chanceCard[7].setType(cardType::MONEY);
  chanceCard[7].setMoney(20);

  chanceCard[8].setType(cardType::MONEY);
  chanceCard[8].setMoney(50);

  chanceCard[9].setType(cardType::MOVE);
  chanceCard[9].setPosition(10);

  chanceCard[10].setType(cardType::MONEY);
  chanceCard[10].setMoney(-15);

  chanceCard[11].setType(cardType::MOVE);
  chanceCard[11].setPosition(37);

  chanceCard[12].setType(cardType::MONEY);
  chanceCard[12].setMoney(150);
  //start writing comch cards
  comChCard[0].setType(cardType::MOVE);
  comChCard[0].setPosition(0);

  comChCard[1].setType(cardType::MONEY);
  comChCard[1].setMoney(200);

  comChCard[2].setType(cardType::MONEY);
  comChCard[2].setMoney(-50);

  comChCard[3].setType(cardType::MONEY);
  comChCard[3].setMoney(50);

  comChCard[4].setType(cardType::MOVE);
  comChCard[4].setPosition(10);

  comChCard[5].setType(cardType::MONEY);
  comChCard[5].setMoney(100);

  comChCard[6].setType(cardType::MONEY);
  comChCard[6].setMoney(20);

  comChCard[7].setType(cardType::MONEY);
  comChCard[7].setMoney(100);

  comChCard[8].setType(cardType::MONEY);
  comChCard[8].setMoney(-100);

  comChCard[9].setType(cardType::MONEY);
  comChCard[9].setMoney(-50);

  comChCard[10].setType(cardType::MONEY);
  comChCard[10].setMoney(25);

  comChCard[11].setType(cardType::MONEY);
  comChCard[11].setMoney(10);

  comChCard[12].setType(cardType::MONEY);
  comChCard[12].setMoney(100);

  comChCard[13].setType(cardType::MONEY);
  comChCard[13].setMoney(-100); 

  int oldBlock[size];
  int dicecall = 0;
  int flag[size];

  for (int i = 0; i < size; i++)
  {
    numrot[i] = 0;
    pl[i].money = 2000;
    oldBlock[i] = 0;
    flag[i] = 0;
  }
  if (run)
  {

    //############ Events in Board  ################

    Board *board = Board::getInstance();
    while ((board->window).isOpen())
    {

      // make_board(board->window,pl,size); // implements code from BoardCode.cpp
      for (int disp_iter = 0; disp_iter < size; disp_iter++)
      {
        disp_icon_i(board->window, plx[disp_iter], ply[disp_iter], pl[disp_iter].icon,pl,size);
      }

      (board->window).display();

      int i = 0;
      bool rolled=false;
      while (!game_end(pl, size))
      { 
	 disp_player_chan(board->window, i, pl, size);
         sf::Event event;
        while((board->window).pollEvent(event))
        {

          if (event.type == sf::Event::Closed)
          {
            (board->window).close();
	    return 0;
          }
 
          if(event.type== sf::Event::MouseButtonPressed)
          {
            if(rectangle1b.getGlobalBounds().contains(sf::Mouse::getPosition(board->window).x, sf::Mouse::getPosition(board->window).y))
            {
              rolled = true;
            }
            if(rectangle2b.getGlobalBounds().contains(sf::Mouse::getPosition(board->window).x, sf::Mouse::getPosition(board->window).y))
            {
              trade(pl,i,size,boughtCoods,board->window);
            }
           if(rectangle3b.getGlobalBounds().contains(sf::Mouse::getPosition(board->window).x, sf::Mouse::getPosition(board->window).y))
            {
              build(pl,i,board->window,coods,size);
            }
            if(rectangle4b.getGlobalBounds().contains(sf::Mouse::getPosition(board->window).x, sf::Mouse::getPosition(board->window).y))
            {
              sell(pl,i,board->window,coods,size); 
            }
	    if (rectangle5b.getGlobalBounds().contains(sf::Mouse::getPosition(board->window).x, sf::Mouse::getPosition(board->window).y))
            {
	      mortgage(pl, i, board->window,size);
            }
            if (rectangle6b.getGlobalBounds().contains(sf::Mouse::getPosition(board->window).x, sf::Mouse::getPosition(board->window).y))
            {
	      unmortgage(pl, i, board->window,size);
            }  
          }
        }
     
  
        roll_die dicecall_struct;
        if(pl[i].is_jail)
        {
            dicecall_struct = jail(pl,&i,&size);
            
        }
        if(rolled && pl[i].get_out_of_jail)
        {
          dicecall_struct = rollDice(); // implements code from diceRoller.cpp
          rolled = false;
          bool plbuy = false;
          
          dicecall=dicecall_struct.dice_1 + dicecall_struct.dice_2;

          //##############  Moving icons #################

          if ((oldBlock[i] + dicecall) > 40)
          {
            numrot[i]++;
            flag[i] = 1;
          }
          for(int m=0;m<dicecall;m++)
          {
	        oldBlock[i] = (oldBlock[i]+1)%40;
          plx[i] = coods[oldBlock[i] ].x;
          ply[i] = coods[oldBlock[i] ].y;
          disp_icon_i(board->window, plx[i], ply[i], pl[i].icon,pl,size);
          sf::sleep(sf::milliseconds(400));
          }
          
          board->window.display();
         
          if (flag[i] == 1)
          {
            pl[i].money += 200;
            flag[i] = 0;
          }
		
          int iter = oldBlock[i];
          //############ Buy property  ################  // From playing_cards.cpp
          if (owners[iter] == 0)
          {
            if(!(Find_card(iter, communityChest) || Find_card(iter, chance) || Find_card(iter, corners) || iter==4 || iter==38 || pl[i].money<=prop_cost[iter]))
            {
            playing_cards(iter,pl[i],i,plbuy);
            if(plbuy==true)
              dispBoughtIcon(iter, i, boughtCoods, board->window, size, pl);
           }
          }
          
            //############ Pay rent  ################

            if (owners[iter] >= 1)
            {
              if (owners[iter] != (i + 1))
              {
                if (iter == 12 || iter == 27) //Utilities
                {
                  if (owners[12] == owners[27])
                  {
                    int utilrent1 = 10 * (dicecall);
                    pl[owners[iter] - 1].money += utilrent1;
                    pl[i].money -= utilrent1;
                  }
                  else
                  {
                    int utilrent2 = 4 * (dicecall);
                    pl[owners[iter] - 1].money += utilrent2;
                    pl[i].money -= utilrent2;
                  }
                }
                if (iter == 5 || iter == 15 || iter == 25 || iter == 35) //Railways
                {
                  if (pl[owners[iter] - 1].count[8] == 1)
                  {
                    pl[owners[iter] - 1].money += 25;
                    pl[i].money -= 25;
                  }
                  if (pl[owners[iter] - 1].count[8] == 2)
                  {
                    pl[owners[iter] - 1].money += 50;
                    pl[i].money -= 50;
                  }
                  if (pl[owners[iter] - 1].count[8] == 3)
                  {
                    pl[owners[iter] - 1].money += 100;
                    pl[i].money -= 100;
                  }
                  if (pl[owners[iter] - 1].count[8] == 4)
                  {
                    pl[owners[iter] - 1].money += 200;
                    pl[i].money -= 200;
                  }
                }
                for (int j = 0; j < 5; j++)//Properties
                {
                  if (houses[iter] == j)
                  {
                    pl[owners[iter] - 1].money += rent[j][iter];
                    pl[i].money -= rent[j][iter];
                  }
                }
              }
            }
              //############ Community Chest  ################

            if (owners[iter] == 0)
            {
              if (Find_card(iter, communityChest))
              {

                //community chest cards random choose
                int randgen = (rand() % 14);
                community_chest(randgen); //  From community_chest.cpp
                if (comChCard[randgen].getType() == cardType::MOVE)
                {
                  plx[i] = coods[comChCard[randgen].getPosition()].x;
                  ply[i] = coods[comChCard[randgen].getPosition()].y;
                  disp_icon_i(board->window, plx[i], ply[i], pl[i].icon,pl,size);
                  oldBlock[i]=comChCard[randgen].getPosition();
                }
                if (randgen == 0) // Both move and money
                {
                  pl[i].money += 200;
                }
                if(randgen==4)
                {
                  pl[i].in_jail=3;
                  pl[i].is_jail=true;
                  pl[i].get_out_of_jail=false;

                }
                if (comChCard[randgen].getType() == cardType::MONEY)
                {
                  pl[i].money += comChCard[randgen].getMoney();
                }
              }
              if (iter == 4)
              {
                pl[i].money += 150;
              }
              //############ Chance card  ################
              if (Find_card(iter, chance))
              {

                chance_card(dicecall); //From chance.cpp
                if (chanceCard[dicecall].getType() == cardType::MOVE)
                {
                  plx[i] = coods[chanceCard[dicecall].getPosition()].x;
                  ply[i] = coods[chanceCard[dicecall].getPosition()].y;
                  disp_icon_i(board->window, plx[i], ply[i], pl[i].icon,pl,size);
                  oldBlock[i]=chanceCard[dicecall].getPosition();
                }
                if (dicecall == 3)
                {
                  pl[i].money += 200;
                }
                if(dicecall==9)
                {
                  pl[i].is_jail=true;
                  pl[i].in_jail=3;
                  pl[i].get_out_of_jail=false;
                }
                if (chanceCard[dicecall].getType() == cardType::MONEY)
                {
                  pl[i].money += chanceCard[dicecall].getMoney();
                }
              }
              if (iter == 30)
              {
                plx[i] = coods[10].x;
                ply[i] = coods[10].y;
		disp_icon_i(board->window, plx[i], ply[i], pl[i].icon,pl,size);
                oldBlock[i]=10;
                pl[i].is_jail=true;
                pl[i].in_jail=3;
                pl[i].get_out_of_jail=false;
                
              }
              if (iter == 38) //Tax
              {
                pl[i].money -= 75;
              }
          
            }
            if (i == (size - 1))
              i = 0;
            else
              i++;
        } // closing for if(roll)
      make_board(board->window,pl,size);
      board->window.display();
      }//while(!end)
      board->window.close();
    }//while(open) 
    disp_win(pl, size);
  }//if run
  return 0;
}//main
