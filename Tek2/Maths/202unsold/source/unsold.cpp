/*
** EPITECH PROJECT, 2019
** 202Unsold
** File description:
** unsold.cpp
*/

#include "unsold.hpp"

unsold::unsold(int a, int b)
{
    _a = a;
    _b = b;

    _offset[0] = {"\t", "X=10\t", "X=20\t", "X=30\t", "X=40\t", "X=50\t",
    "Y law"};
    _offset[1] = {"Y=10\t"};
    _offset[2] = {"Y=20\t"};
    _offset[3] = {"Y=30\t"};
    _offset[4] = {"Y=40\t"};
    _offset[5] = {"Y=50\t"};
    _offset[6] = {"X law\t"};
}

unsold::~unsold()
{}

float unsold::make_operation(float Y, float X)
{
    return (((_a - X) * (_b - Y)) / ((5 * _a - 150) * (5 * _b - 150)));
}

void unsold::probability(void)
{
    for (int Y = 0; Y < 5; Y += 1) {
        for (int X = 0; X < 5; X += 1) {
            _table[Y][X] = make_operation((Y + 1) * 10, (X + 1) * 10);
        }
    }

    total();
}

void unsold::total(void)
{
    for (int i = 0; i < 6; i += 1) {
        _table[i][5] = _table[i][0] + _table[i][1] + _table[i][2]
        + _table[i][3] + _table[i][4];
    }

    for (int i = 0; i < 6; i += 1) {
        _table[5][i] = _table[0][i] + _table[1][i] + _table[2][i]
        + _table[3][i] + _table[4][i];
    }
}

void unsold::display_third_part()
{
    printf("expected value of X:\t%.1f\nvariance of X:\t\t%.1f\n",
      compute_expected_x(), compute_variance_x());
    printf("expected value of Y:\t%.1f\nvariance of Y:\t\t%.1f\n",
      compute_expected_y(), compute_variance_y());
    printf("expected value of Z:\t%.1f\nvariance of Z:\t\t%.1f\n",
      compute_expected_z(), compute_variance_z());
    printf("––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
}

void unsold::display_second_part()
{
    printf("z\t20\t30\t40\t50\t60\t70\t80\t90\t100\ttotal\np(Z=z)\t");
    printf("%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t1\n",
      compute_z(20), compute_z(30), compute_z(40), compute_z(50),
      compute_z(60), compute_z(70), compute_z(80), compute_z(90),
      compute_z(100));
    printf("––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
}

void unsold::display_first_part()
{
    printf("––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");

    for (int i = 0; i < 7; i += 1) {
        std::cout << _offset[0][i];
    }

    std::cout << std::endl;

    for (int i = 0; i < 6; i += 1) {
        std::cout << _offset[i + 1][0];

        for (int j = 0; j < 6; j += 1) {
            if (_table[i][j] == 1) {
                printf("1");
            } else if (j == 5) {
              printf("%.3f", _table[i][j]);
            } else {
                printf("%.3f\t", _table[i][j]);
            }
        }

        std::cout << std::endl;
    }

    printf("––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
}

float unsold::compute_z(int Z)
{
    switch (Z) {
        case 20:
            return (_table[0][0]);
            break;
        case 30:
            return (_table[0][1] + _table[1][0]);
            break;
        case 40:
            return (_table[0][2] + _table[1][1] + _table[2][0]);
            break;
        case 50:
            return (_table[0][3] + _table[1][2] + _table[2][1] + _table[3][0]);
            break;
        case 60:
            return (_table[0][4] + _table[1][3] + _table[2][2] + _table[3][1] + _table[4][0]);
            break;
        case 70:
            return (_table[1][4] + _table[2][3] + _table[3][2] + _table[4][1]);
            break;
        case 80:
            return (_table[2][4] + _table[3][3] + _table[4][2]);
            break;
        case 90:
            return (_table[3][4] + _table[4][3]);
            break;
        case 100:
            return (_table[4][4]);
            break;
        default:
            return (-1);
    }
}

float unsold::compute_expected_x()
{
    float expected = 0;
    float mult = 10;

    for (int i = 0; i != 5 ; ++i, mult += 10) {
        expected += _table[5][i] * mult;
    }

    return (expected);
}

float unsold::compute_expected_y()
{
    float expected = 0;
    float mult = 10;

    for (int i = 0; i != 5 ; ++i, mult += 10) {
        expected += _table[i][5] * mult;
    }

    return (expected);
}

float unsold::compute_expected_z()
{
    return (compute_expected_x() + compute_expected_y());
}

float unsold::compute_variance_x()
{
    float expected = 0;
    float variance = 0;
    float mult = 10;

    expected = compute_expected_x();

    for (int i = 0 ; i != 5 ; ++i, mult += 10) {
        variance += _table[5][i] * pow((mult - expected), 2);
    }

    return (variance);
}

float unsold::compute_variance_y()
{
    float expected = 0;
    float variance = 0;
    float mult = 10;

    expected = compute_expected_y();

    for (int i = 0 ; i != 5 ; ++i, mult += 10) {
        variance += _table[i][5] * pow((mult - expected), 2);
    }

    return (variance);
}

float unsold::compute_variance_z()
{
    return (compute_variance_x() + compute_variance_y());
}
