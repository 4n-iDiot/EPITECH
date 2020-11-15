#!/usr/bin/env python3

import sys
from math import *
import numpy as np

couples = []
names = []


def adjacacent_matrix():
    matrix = np.array([[0 for y in range(len(names))] for x in range(len(names))])

    for couple in couples:
        x = names.index(couple[0])
        y = names.index(couple[1])
        matrix[x][y] = 1
        matrix[y][x] = 1

    return(matrix)


def init_matrix(matrix, n):
    init_matrix = np.array([[0 for y in range(len(names))] for x in range(len(names))])

    for x in range(len(names)):
        for y in range(len(names)):
            init_matrix[x][y] = n + 1

        for y in range(len(names)):
            if (matrix[x][y] > 0):
                init_matrix[x][y] = 1

        init_matrix[x][x] = 0

    return(last_matrix(init_matrix, n))


def last_matrix(matrix, n):
    for k in range(len(names)):
        for x in range(len(names)):
            for y in range(len(names)):
                matrix[x][y] = min(matrix[x][y], matrix[x][k] + matrix[k][y])

                if ((k == len(names) - 1) and (matrix[x][y] > n)):
                    matrix[x][y] = 0

    return(matrix)


def get_names_in_order():
    for couple in couples:
        for name in couple:
            if name not in names:
                names.append(name)

    names.sort()


def get_couples(files):
    global couples

    try:
        files = open(files, 'r')
    except FileNotFoundError:
        print("File does not exist")
        exit(84)

    file = files.readline()

    while file:
        file = str(file).strip('\n')
        name = file.split(" is friends with ")
        file = files.readline()
        couples.append(name)

    get_names_in_order()


def print_3_args():
    for name in names:
        print(name)

    print("")

    for line in matrix:
        print(*line, sep=" ")

    print("")

    for line in last_matrix:
        print(*line, sep=" ")


def check_args():
    if (len(sys.argv) == 3):
        try:
            val = int(sys.argv[2])
        except ValueError:
            print("Argument is not an int")
            exit(84)

        if (val < 0):
            print("Argument must a positive int !")
            exit(84)

if __name__ == "__main__":
    try:
        if (len(sys.argv) == 2 and sys.argv[1] == "-h"):
            print("USAGE\n\t./302separation file [n | p1 p2]\n\nDESCRIPTION\n\tfile\tfile that contains the list of Facebook connections\n\tn\tmaximum length of the paths\n\tpi\tname of someone in the file")
            exit(0)
        elif (len(sys.argv) == 3 or len(sys.argv) == 4):
            get_couples(sys.argv[1])
            check_args()
            matrix = adjacacent_matrix()

            if (len(sys.argv) == 3):
                last_matrix = init_matrix(matrix, int(sys.argv[2]))
                print_3_args()
            elif (len(sys.argv) == 4):
                last_matrix = init_matrix(matrix, len(names) - 1)

                if not sys.argv[2] in names or not sys.argv[3] in names:
                    output = -1
                else:
                    output = last_matrix[names.index(sys.argv[2])][names.index(sys.argv[3])]

                print("Degree of separation between %s and %s: %i" % (sys.argv[2], sys.argv[3], output))

            exit(0)
    except ValueError:
        print("Bad argument")

    exit(84)
