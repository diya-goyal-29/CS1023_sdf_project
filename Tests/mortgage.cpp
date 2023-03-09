#include<gtest/gtest.h>
#include<string>
#include<sstream>
#include"mortgage.h"

int mortgage_values[40] = { 0,40,0,40,0,100,50,50,0,100,0,70,75,70,80,100,75,0,80,100,0,110,0,110,120,100,110,75,160,140,0,160,160,0,165,100,0,160,0,175 };

void mortgage(player& pl,sf::Text playerText) 
{
	std::stringstream ss(playerText.getString().toAnsiString());
	int id;
	ss >> id;
	
	if (std::find(pl.playerProps,pl.playerProps+40,id)!=std::end(pl.playerProps)); 
	{
		pl.money += mortgage_values[id];
		pl.playerMortProps[id] = id;
		owners[id]*=-1;
		pl.numbMortProps += 1;
		pl.playerValue -= prop_cost[id];
	}
}

void unmortgage(player& pl,sf::Text playerText) 
{
	std::stringstream ss(playerText.getString().toAnsiString());
	int id;
	ss >> id;
	
	if (std::find(pl.playerProps,pl.playerProps+40,id)!=std::end(pl.playerProps)); 
	{
		pl.money -= (1.05*mortgage_values[id]);
		pl.playerMortProps[id] = 0;
		owners[id]*=-1;
		pl.numbMortProps -= 1;
		pl.playerValue += prop_cost[id];
	}
}

class MortgageTest : public ::testing::Test 
{
 protected:
  void SetUp() override {

	for(int i = 0; i < 60; i++)
	{
		j=rand()%40;
		pl[i].playerProps[j]=(rand()%40);
		initial_money[i]= pl[i].money;
		playerText[i].setString(std::to_string(pl[i].playerProps[j]));
		mortgage(pl[i],playerText[i]);
	}
  }

  void SetUp_unmortgage()
  {
	for(int i = 0; i < 60; i++)
	{
		unmortgage(pl[i],playerText[i]);
	} 
  }

  player pl[60];
  int j;
  int initial_money[60];
  sf::Text playerText[60];
};


TEST_F(MortgageTest,moneyExchange)
{	
	for(int i = 0; i < 60; i++)
	{
		if(pl[i].numbMortProps >=1 )
		{
			
			EXPECT_GE(pl[i].money,initial_money[i]);
		}
	}
}

TEST_F(MortgageTest,unmortgage_moneyExchange)
{
	for(int i = 0; i < 60; i++)
	{
		if(pl[i].numbMortProps >=1 )
		{
			SetUp_unmortgage();
			EXPECT_LE(pl[i].money,initial_money[i]);
		}
	}
}




