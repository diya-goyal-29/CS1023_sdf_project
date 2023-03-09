#include"../Code/players.h"
#include"../Code/properties.h"
#include"../Code/cards.h"
#include"build.h"
#include<gtest/gtest.h>

void build(player& p,int property_num,int num_of_houses)
{
	if ( ! ( Find_card(property_num, communityChest) || Find_card(property_num, chance) || Find_card(property_num,corners)) )
	{
		int find = Find_group(property_num);
		if (p.count[find] == p.max_count[find])
		{ 
			int j=num_of_houses==5?1:0;
			p.playerHouses[property_num]+=num_of_houses;
			p.money -= ((num_of_houses)*(house_cost[p.playerProps[property_num]][j]));
			houses[property_num]+=num_of_houses;
			p.playerValue += (num_of_houses)*( house_cost[p.playerProps[property_num]][j] );
		
		}
	}
}

class BuildTest : public ::testing::Test 
{
 protected:
  void SetUp() override {

	for(int i = 0; i < 60; i++)
	{

		for(int j=0;j<8;j++)
		{
			pl[i].count[j] = ( rand()%(pl[i].max_count[j] +1) );	
		}
		j=rand()%40;
		pl[i].playerProps[j]=(rand()%40);
		initial_money[i]= pl[i].money;
		build(pl[i],pl[i].playerProps[j],3);
	}
  }

  player pl[60];
  int j;
  int initial_money[60];
};


TEST_F(BuildTest,hasGroup)
{
		
	for(int i = 0; i < 60; i++)
	{

		if(pl[i].playerHouses[ pl[i].playerProps[j] ] >=1 )
		{
			int find = Find_group(pl[i].playerProps[j]);
			EXPECT_EQ(pl[i].count[find],pl[i].max_count[find]);
		}
	}
}

TEST_F(BuildTest,moneyExchange)
{
	for(int i = 0; i < 60; i++)
	{
		if(pl[i].playerHouses[ pl[i].playerProps[j] ] >=1 )
		{
			EXPECT_LE(initial_money[i],pl[i].money);
		}
	}
}
