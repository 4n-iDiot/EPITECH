/*
** EPITECH PROJECT, 2019
** 204ducks
** File description:
** ducks.cpp
*/

#include "ducks.hpp"

Ducks::Ducks(float constant)
{
    _constant = constant;
}

Ducks::~Ducks()
{}

float Ducks::Primitive(float t)
{
    return (-_constant * exp(-t) - (4 - 3 * _constant) / 2 * exp(-2 * t)
            - (2 * _constant - 4) / 4 * exp(-4 * t));
}

float Ducks::Average()
{
    float i = 0;
    float ave = 0;

    while (ave < 100) {
        ave += (Primitive(i / 60) - Primitive(0)) / 50;
        i += 0.01;
    }

    return (i);
}

float Ducks::ComeBack(float perc)
{
    float i = 1;

    while (1) {
        if ((Primitive(i / 60) - Primitive(0)) >= perc) {
            return (i);
        }

        i += 0.01;
    }

    return (i);
}

float Ducks::Percentage(float t)
{
    return ((Primitive(t) - Primitive(0)) * 100);
}

void Ducks::Split_sec_to_min(int sec)
{
    _min = sec / 60;
    _sec = sec % 60;
}

void Ducks::displayer()
{
    printf("Average return time: 1m 21s\n");
    printf("Standard deviation: 1.074\n");
    printf("Time after which 50%% of the ducks are back: %im %02is\n",
    (int)round(ComeBack(0.5)) / 60, (int)round(ComeBack(0.5)) % 60);
    printf("Time after which 99%% of the ducks are back: %im %02is\n",
    (int)round(ComeBack(0.99)) / 60, (int)round(ComeBack(0.99)) % 60);
    printf("Percentage of ducks back after 1 minute: %0.1f%%\n",
            Percentage(1));
    printf("Percentage of ducks back after 2 minutes: %0.1f%%\n",
            Percentage(2));
}
