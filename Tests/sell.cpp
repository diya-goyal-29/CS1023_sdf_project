#include"../Code/players.h"
#include"../Code/properties.h"
#include"../Code/cards.h"
#include"build.h"
#include<gtest/gtest.h>

void sell(player& p,int property_num,int num_of_houses)
{
	if(num_of_houses<p.playerHouses[property_num])
	{
		int j=num_of_houses==5?1:0;
		p.playerHouses[property_num]-=num_of_houses;
		p.money += ((num_of_houses)*(house_cost[p.playerProps[property_num]][j]));
		houses[property_num]-=num_of_houses;
		p.playerValue -= (num_of_houses)*( house_cost[p.playerProps[property_num]][j] );
	}
}

class SellTest : public ::testing::Test 
{
 protected:
  void SetUp() override {

	for(int i = 0; i < 60; i++)
	{
		j=rand()%40;
		pl[i].playerProps[j]=(rand()%40);
		initial_houses[i]=rand()%5 + 1;
		pl[i].playerHouses[j]=initial_houses[i];
		initial_money[i]= pl[i].money;
		sell(pl[i],pl[i].playerProps[j],3);
	}
  }

  player pl[60];
  int j;
  int initial_money[60];
  int initial_houses[60];
};


TEST_F(SellTest,sellCondition)
{
	for(int i = 0; i < 60; i++)
	{
		if(initial_houses[i]<3)
		{
			EXPECT_EQ(initial_money[i],pl[i].money);
		}
	}
}


TEST_F(SellTest,moneyExchange)
{
	for(int i = 0; i < 60; i++)
	{
		EXPECT_LE(initial_money[i],pl[i].money);
	}
}


