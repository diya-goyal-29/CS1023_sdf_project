#ifndef CARDS_H
#define CARDS_H
#include<iostream>
#include<array>

enum class cardType
{
  MOVE,
  MONEY
};

extern std::array<int, 3> communityChest , chance ;
extern std::array<int, 4> corners;

/**
 * @brief card is class that creates cards of particular type. Each card
 * can set money or position according to its type.
 * 
 */
class card
{
  cardType type; // type of card (either money or position).
  int pos; // position to which the card moves the player.
  int money; // money which is added or deducted from player's money.

public:
/**
 * @brief Sets the Type of card
 * 
 * @param _type type of the card
 */
  void setType(cardType _type)
  {
    type = _type;
  }
  /**
   * @brief Sets the position to which the card moves the player.
   * 
   * @param _pos positon to be set.
   */
  void setPosition(int _pos)
  {
    pos = _pos;
  }
  /**
   * @brief Get the Position object
   * 
   * @return int position.
   */
  int getPosition()
  {
    return pos;
  }
  /**
   * @brief Set the Money which is added or deducted from player's money.
   * 
   * @param _money money to be set.
   */
  void setMoney(int _money)
  {
    money = _money;
  }
  /**
   * @brief Get the Money object
   * 
   * @return int money
   */
  int getMoney()
  {
    return money;
  }
  /**
   * @brief Get the Type of card.
   * 
   * @return cardType type of card.
   */
  cardType getType()
  {
    return type;
  }
};

/**
 * @brief Find_card function checks whether the given property is present in the given array or not.
 * 
 * @tparam s size of the places array.
 * @param i index of the property.
 * @param arr array in which we have to check the property.
 * @return  returns true if property is present in the array else false.
 */
template <std::size_t s>
bool Find_card(int i, std::array<int, s> arr)
{
  auto find = std::find(arr.begin(), arr.end(), i);
  if (find != arr.end())
    return true;
  return false;
}


#endif