/*
** EPITECH PROJECT, 2019
** 201yams
** File description:
** calcul.cpp
*/

#include "yams.hpp"

Calcul::Calcul(std::string type)
{
  std::vector<std::string> array;
  std::string tmp;

  std::replace(type.begin(), type.end(), '_', ' ');
  std::stringstream ss(type);

  while (ss >> tmp) {
      array.push_back(tmp);
  }

  if (array.size() == 2) {
    _type = array[0];
    _a = atoi(array[1].c_str());
    _b = -1;
  } else if (array.size() == 3) {
    _type = array[0];
    _a = atoi(array[1].c_str());
    _b = atoi(array[2].c_str());
  }
}

Calcul::~Calcul()
{
}

int Calcul::add_dice(char *dice)
{
  int new_dice = 0;

  if ((_type != "yams" && _type != "full" && _type != "straight"
    && _type != "pair" && _type != "four" && _type != "three")
    || (_a < 1 || _a > 6) || ((_b < 1 || _b > 6) && _b != -1)) {
      return (1);
    }

  if ((_type == "full" && (_a == 0 || _b == -1))
    || (_type == "straight" && _a != 5 && _a != 6)) {
      return (1);
    }

  if (strlen(dice) == 1 && (dice[0] >= '0' && dice[0] <= '9')) {
    new_dice = std::stoi(dice);
  } else {
    return (1);
  }

  if (new_dice < 7 && _dice.size() < 5) {
    _dice.push_back(new_dice);
    std::sort(_dice.begin(), _dice.end());

    return (0);
  } else {
    return (1);
  }
}

int Calcul::factorial(int nbr)
{
  int fact = 1;

  for (int i = 1; i <= nbr; ++i) {
    fact *= i;
  }

  return fact;
}

int Calcul::cnp(int a, int b)
{
  if (a == b) {
    return (1);
  }

  return factorial(a) / (factorial(b) * factorial(a - b));
}

// Constructor / Deconstructor
//
// Algorithm

float Calcul::algorithm()
{
  if (_type == "yams") {
    _type = "yams";

    return yams();
  } else if (_type == "straight") {
    _type = "straight";

    return straight();
  } else if (_type == "full") {
    _type = "full of";
  }

  if (full() > -1) {
    return full();
  } else if (_type == "four") {
    _type = "four-of-a-kind";

    return four();
  } else if (_type == "three") {
    _type = "three-of-a-kind";

    return three();
  } else if (_type == "pair") {
    _type = "pair";

    return pair();
  }

  return 0;
}

float Calcul::yams()
{
  for (unsigned int i = 0 ; i != _dice.size() ; i++) {
    if (_dice[i] != _a) {
      _nbrDice += 1;
    }
  }

  if (_nbrDice == 0) {
    return (100);
  }

  return ((1 / pow(6, _nbrDice)) * 100);
}

bool Calcul::check_in_dice(int _nbrStraight)
{
  for (unsigned int i = 0 ; i != _dice.size() ; i++) {
    if (_dice[i] == _nbrStraight) {
      return (true);
    }
  }

  return (false);
}

float Calcul::straight()
{
  std::vector<int> straight;

  if (_a == 5) {
    straight = {1, 2, 3, 4, 5};
  } else if (_a == 6) {
    straight = {2, 3, 4, 5, 6};
  }

  for (unsigned int i = 0 ; i != straight.size() ; i++) {
    if (check_in_dice(straight[i]) == true) {
      _nbrDice += 1;
    }
  }

  if (_nbrDice == 5) {
    return (100);
  } else {
    return (factorial(5 - _nbrDice) / pow(6, 5 - _nbrDice) * 100);
  }

  return (-1);
}

float Calcul::full()
{
  int a = 0;
  int b = 0;

  for (unsigned int i = 0 ; i != _dice.size() ; i++) {
    if (_dice[i] == _a) {
      a++;
    } else if (_dice[i] == _b) {
      b++;
    }
  }

  if (a == 3 && b == 2) {
    return (100);
  }

  if (a > 3) {
    a = 3;
  }

  if (b > 2) {
    b = 2;
  }

  return ((1 / pow(6, 3 - a + 2 - b)) * 100);
}

float Calcul::four()
{
  int _nbrFour = 0;
  float res = 0;

  for (unsigned int i = 0 ; i != _dice.size() ; i++) {
    if (_dice[i] != _a) {
      _nbrDice += 1;
    }
  }

  if (_nbrDice <= 1) {
    return (100);
  }

  _nbrFour = 5 - _nbrDice;

  for (int i = 4 - _nbrFour ; i != (5 - _nbrFour) ; i++) {
    res +=
    (factorial(5 - _nbrFour) / (factorial(i) * factorial(5 - _nbrFour - i))) *
    (1 / pow(6, i)) * (pow(5, 5 - _nbrFour - i) / pow(6, 5 - _nbrFour - i));
  }

  res += 1 / pow(6, _nbrDice);

  return res * 100;
}

float Calcul::three()
{
  int _nbrThree = 0;
  float res = 0;

  for (unsigned int i = 0 ; i != _dice.size() ; i++) {
    if (_dice[i] != _a) {
      _nbrDice += 1;
    }
  }

  if (_nbrDice <= 2) {
    return (100);
  }

  _nbrThree = 5 - _nbrDice;

  for (int i = 3 - _nbrThree ; i != (5 - _nbrThree) ; i++) {
    res +=
    (factorial(5 - _nbrThree) / (factorial(i) * factorial(5 - _nbrThree - i))) *
    (1 / pow(6, i)) * (pow(5, 5 - _nbrThree - i) / pow(6, 5 - _nbrThree - i));
  }

  res += 1 / pow(6, _nbrDice);

  return res * 100;
}

float Calcul::pair()
{
  int _nbrPair = 0;
  float res = 0;

  for (unsigned int i = 0 ; i != _dice.size() ; i++) {
    if (_dice[i] != _a) {
      _nbrDice += 1;
    }
  }

  if (_nbrDice <= 3) {
    return (100);
  }

  _nbrPair = 5 - _nbrDice;

  for (int i = 2 - _nbrPair ; i != (5 - _nbrPair) ; i++) {
    res +=
    (factorial(5 - _nbrPair) / (factorial(i) * factorial(5 - _nbrPair - i))) *
    (1 / pow(6, i)) * (pow(5, 5 - _nbrPair - i) / pow(6, 5 - _nbrPair - i));
  }

  res += 1 / pow(6, _nbrDice);

  return res * 100;
}

// Algorithm
//
// Debug

void Calcul::debug()
{
  for (int i = 0; i < 5; i += 1) {
    std::cout << _dice[i] << std::endl;
  }

  std::cout << _type << _a << _b << std::endl;
}

// Debug
//
// Display

void Calcul::display(float percent)
{
  if (!(_b == -1)) {
    printf("chances to get a %i %s %i: %.2f%%\n", _a, _type.c_str(), _b, percent);
  } else {
    printf("chances to get a %i %s: %.2f%%\n", _a, _type.c_str(), percent);
  }
}
