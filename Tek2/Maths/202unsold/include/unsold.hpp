/*
** EPITECH PROJECT, 2019
** 202Unsold
** File description:
** unsold.hpp
*/

#ifndef UNSOLD_HPP_
    #define UNSOLD_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <fstream>

class unsold {
    public:
        unsold(int a, int b);
        ~unsold();

        void probability();
        void total();
        float make_operation(float, float);
        float compute_z(int);
        float compute_expected_x();
        float compute_expected_y();
        float compute_expected_z();
        float compute_variance_x();
        float compute_variance_y();
        float compute_variance_z();

        void display_first_part();
        void display_second_part();
        void display_third_part();
    private:
        int _a;
        int _b;

        std::array<std::vector<std::string>, 7> _offset;
        std::array<std::array<float, 6>, 6> _table;
};

#endif /* UNSOLD_HPP_ */
