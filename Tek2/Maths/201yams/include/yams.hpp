/*
** EPITECH PROJECT, 2019
** 201yams
** File description:
** yams.hpp
*/

#ifndef YAMS_HPP_
    #define YAMS_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <fstream>
#include <math.h>
#include <iomanip>

class Calcul {
  public:
    Calcul(std::string type);
    ~Calcul();

    int factorial(int);
    int cnp(int, int);

    float algorithm();

    float pair();
    float three();
    float four();
    float full();
    float straight();
    bool check_in_dice(int);
    float yams();

    int add_dice(char *dice);
    void display(float percent);
    void debug();

  private:
    std::string _type;
    std::vector<int> _dice;
    int _a;
    int _b;
    int _nbrDice = 0;
};

#endif /* YAMS_HPP_ */
