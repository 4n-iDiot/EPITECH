/*
** EPITECH PROJECT, 2019
** 204ducks
** File description:
** ducks.hpp
*/

#ifndef DUCKS_HPP_
    #define DUCKS_HPP_

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

class Ducks {
    public:
        Ducks(float);
        ~Ducks();

        float Primitive(float t);
        float Average();
        float Percentage(float t);
        float ComeBack(float);
        void Split_sec_to_min(int sec);
        void displayer();

    private:
        float _constant;
        int _min;
        int _sec;
};

#endif /* DUCKS_HPP_ */
