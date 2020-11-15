#!/usr/bin/env python3

import sys
from math import *

# GLOBALS
vars = {'r0': 0, 'r5': 0, 'r10': 0, 'r15': 0, 'r20': 0, 'n': 0}
vector = [0, 0, 0, 0, 0]
abscissas = [0, 5, 10, 15, 20]
ordinate = []
radiis = []
nbrOfAbs = 0


# DISPLAY RESULT
def display():
    check_vector()

    print("vector result: [%.1f, %.1f, %.1f, %.1f, %.1f]" % (vector[0], vector[1], vector[2], vector[3], vector[4]))

    for i in range(int(vars['n'])):
        print("abscissa: %.1f cm\tradius: %.1f cm" %(nbrOfAbs * i, radiis[i]))



# COMPUTE VALUES
def get_vect_abs(abs, j):
    return ((vector[j] * pow(abs - abscissas[j - 1], 3) - vector[j - 1] * pow(abs - abscissas[j], 3)) / 30)


def get_vect_ord(abs, j, isPos):
    if (not isPos):
        return ((ordinate[j - 1] / 5 - 5 / 6 * vector[j - 1]) * (abs - abscissas[j]) * (-1))
    else:
        return ((ordinate[j] / 5 - 5 / 6 * vector[j]) * (abs - abscissas[j - 1]))


def compute_values():
    for i in range(int(vars['n'])):
        abs = nbrOfAbs * i
        j = int((abs - 0.01) / 5) + 1
        radii = get_vect_abs(abs, j) + get_vect_ord(abs, j, False) + get_vect_ord(abs, j, True)
        radiis.append(radii)



# COMPUTE VECTOR
def check_vector():
    for i in range(len(vector)):
        vector[i] = round(vector[i], 1)
        if (vector[i] == 0):
            vector[i] = 0


def compute_vector():
    x = vars['r10'] - 2 * vars['r5'] + vars['r0']
    y = vars['r15'] - 2 * vars['r10'] + vars['r5']
    z = vars['r20'] - 2 * vars['r15'] + vars['r10']
    const = 6 * (4 * y - (x + z))
    vector[2] = 4 * const / 1400
    vector[1] = (84 * x - const) / 1400
    vector[3] = (84 * z - const) / 1400



# ARGS CHECK
def fill_vars():
    for i, j in zip(vars, range(1, len(sys.argv))):
        if (not isFloat(sys.argv[j])):
            exit(84)

        number = float(sys.argv[j])

        if (number <= 0):
            print("Argument must be a positive number")
            exit(84)

        if (j is not (len(sys.argv) - 1)):
            ordinate.append(number)

        vars[i] = number

def isFloat(arg):
    try:
        number = float(arg)
    except ValueError:
        print("Argument is not a number")
        return (False)

    return (True)



# MAIN
if __name__ == "__main__":
    try:
        if (len(sys.argv) == 2 and sys.argv[1] == "-h"):
            print("USAGE\n\t"
            "./308reedpipes r0 r5 r10 r15 r20 n\n\n"
            "DESCRIPTION\n\t"
            "r0\tradius\t(in cm) of pipe at the 0cm abscissa\n\t"
            "r5\tradius\t(in cm) of pipe at the 5cm abscissa\n\t"
            "r10\tradius\t(in cm) of pipe at the 10cm abscissa\n\t"
            "r15\tradius\t(in cm) of pipe at the 15cm abscissa\n\t"
            "r20\tradius\t(in cm) of pipe at the 20cm abscissa\n\t"
            "n\tnumber\tof points needed to display the radius")
            exit(0)
        elif (len(sys.argv) == 7):
            fill_vars()
            nbrOfAbs = 20 / (vars['n'] - 1)
            compute_vector()
            compute_values()
            display()
#            printValue()
            exit(0)
    except ValueError:
        print("Bad arguments")

    exit(84)
