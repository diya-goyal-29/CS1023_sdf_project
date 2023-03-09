#include<gtest/gtest.h>
#include"dice.h"

int rollDice()
{
	srand(time(0));
	int i = rand() % 6;
	int j = rand() % 6;
	return (i+j+2);
}

TEST(DICETEST,inRange)
{
	int diceResult;
	for(int i = 0; i < 60; i++)
	{
		diceResult = rollDice();
		EXPECT_LE(2,diceResult);
		EXPECT_LE(diceResult,12);
	}
}


