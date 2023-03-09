#include<vector>
#include<algorithm>
#include<array>
#include"properties.h"

std::array<std::string, 40> places =
    {
	"GO",
	"GUWAHATI",
	"COMCH1",
	"BHUBANESHWAR",
	"TAXREF",
	"CHENCENTR",
	"PANAJI",
	"AGRA",
	"CHANCE1",
	"VADODARA",
	"JAIL",
	"LUDHIANA",
	"ELEC",
	"PATNA",
	"BHOPAL",
	"HOWRSTAT",
	"INDORE",
	"COMCH2",
	"NAGPUR",
	"KOCHI",
	"FREEPARK",
	"LUCKNOW",
	"CHANCE2",
	"CHANDIGARH",
	"JAIPUR",
	"DELHISTAT",
	"PUNE",
	"WATER",
	"HYDERABAD",
	"AHMEDABAD",
	"GOTOJAIL",
	"KOLKATA",
	"CHENNAI",
	"COMCH3",
	"BANGALORE",
	"MUMBAISTAT",
	"CHANCE3",
	"DELHI",
	"TAX",
	"MUMBAI"};

int owners[40] = {0}; //{0, 1, 0, 0, 0, ...0}<--40 elem,
std::vector<std::vector<int>> group{{{1, 3}, {6, 7, 9}, {11, 13, 14},

				 {16, 18, 19}, {21, 23, 24}, {26, 28, 29}, {31, 32, 34}, {37, 39}, {5, 15, 25, 35}}};
int Find_group(int i)
{
  int j;
  for (j = 0; j < 8; j++)
  {
    auto find = std::find(begin(group[j]), end(group[j]), i);
    if (find != std::end(group[j]))
    {
      break;
    }
  }
  return j;
}

int rent[6][40] = {{//0 houses
                      0, 6, 0, 8, 0, 0, 10, 10, 0, 10, 0, 14, 0, 14, 16, 0, 15, 0, 16, 20, 0, 22, 0, 22, 24, 0, 22, 0, 32, 28, 0, 32, 32, 0, 33, 0, 0, 32, 0, 35},

                     //1 house
                     {0, 20, 0, 20, 0, 0, 30, 30, 0, 30, 0, 50, 0, 0, 60, 50, 70, 0, 70, 80, 0, 90, 0, 90, 100, 0, 110, 0, 120, 110, 0, 130, 130, 0, 150, 0, 0, 175, 0, 200},

                     //2 houses
                     {0, 40, 0, 60, 0, 0, 90, 90, 0, 90, 0, 150, 0, 150, 250, 0, 200, 0, 200, 220, 0, 250, 0, 250, 300, 0, 330, 0, 360, 330, 0, 390, 390, 0, 450, 0, 0, 500, 0, 600},

                     //3 houses
                     {0, 90, 0, 180, 0, 0, 270, 270, 0, 270, 0, 450, 0, 450, 500, 0, 550, 0, 550, 600, 0, 700, 0, 700, 750, 0, 800, 0, 850, 800, 0, 900, 900, 0, 1000, 0, 0, 1100, 0, 1400},

                     // 4 houses
                     {0, 160, 0, 320, 0, 0, 400, 400, 0, 400, 0, 625, 0, 625, 700, 0, 750, 0, 750, 800, 0, 875, 0, 875, 925, 0, 975, 0, 1025, 975, 0, 1100, 1100, 0, 1200, 0, 0, 1300, 0, 1700},

                     // 5 houses / hotel
                     {0, 250, 0, 450, 0, 0, 550, 550, 0, 550, 0, 750, 0, 750, 900, 0, 950, 0, 950, 1000, 0, 1050, 0, 1050, 1100, 0, 1150, 0, 1200, 1150, 0, 1275, 1275, 0, 1400, 0, 0, 1500, 0, 2000}};

int house_cost[40][2] = {
				{0,0},{40,70},{0,0},{40,70},{0,0},{0,0},{50,50},{50,80},{0,0},{100,150},
				{0,0},{100,150},{0,0},{100,150},{150,200},{0,0},{175,250},{0,0},{175,250},{200,275},
				{0,0},{200,350},{0,0},{200,350},{250,450},{0,0},{350,500},{0,0},{325,450},{300,450},
				{0,0},{350,500},{350,500},{0,0},{375,525},{0,0},{0,0},{400,550},{0,0},{400,550},	
			};

int houses[40]={0};

int prop_cost[40] = {0, 60, 0, 80, 0, 200, 100, 100, 0, 100, 0, 140, 150, 140, 160, 200, 150, 0, 160, 200, 0, 220, 0, 220, 240, 200, 220, 150, 325, 280, 0, 320, 320, 0, 330, 200, 0, 325, 0, 350};