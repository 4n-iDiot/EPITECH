#!/usr/bin/env python3

import sys
from math import *

n = 0
points = []
x = 0
y = 0
matrice = []



# CALCULUS
def compute_bezier():
    res = 0

    for i in range(n):
        for j in range(n):
            res += compute_bernstein(x, n - 1, j) * compute_bernstein(y, n - 1, i) * matrice[i][j]

    print("{:.2f}".format(res))


def compute_bernstein(u, m, i):
    c = factorial(m) / (factorial(i) * factorial(m - i))

    return (c * pow(u, i) * pow(1 - u, m - i))



# FILLING MATRICE AND POINTS
def set_matrice():
    for _ in range(0, n):
        matrice.append([0] * n)

    for point in points:
        if (point[0] < 0 or point[0] > n - 1 or point[1] < 0 or point[1] > n - 1):
            exit(84)

        matrice[point[1]][point[0]] = point[2]


def get_points(files):
    try:
        files = open(files, 'r')
    except FileNotFoundError:
        print("File does not exist")
        exit(84)

    file = files.readline()

    while file:
        file = str(file).strip('\n')
        lign = file.split(';')
        points.append([int(lign[0]), int(lign[1]), int(lign[2])])
        file = files.readline()



# ARG CHECKS
def check_arg():
    global n, x, y

    try:
        n = int(sys.argv[1])
        x = float(sys.argv[3])
        y = float(sys.argv[4])
        x /= n - 1
        y /= n - 1
    except ValueError:
        print("Values must be numbers")
        exit(84)

    if (n < 0 or x < 0 or y < 0 or x > n or y > n):
        print("Values must be positive integers and x and y must be under n")
        exit(84)



# MAIN
if __name__ == "__main__":
    try:
        if (len(sys.argv) == 2 and sys.argv[1] == "-h"):
            print("USAGE\n\t"
            "./309pollution n file x y\n\n"
            "DESCRIPTION\n\t"
            "n\tnumber of points on the grid axis\n\t"
            "file\tcsv file containing the data points x;y;p\n\t"
            "x\tabscissa of the point whose pollution level we want to know\n\t"
            "y\tordinate of the point whose pollution level we want to know")
            exit(0)
        elif (len(sys.argv) == 5):
            check_arg()
            get_points(sys.argv[2])
            set_matrice()
            compute_bezier()
            exit(0)
    except ValueError:
        print("Bad arguments")

    exit(84)
