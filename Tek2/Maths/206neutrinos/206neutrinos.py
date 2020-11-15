#!/usr/bin/env python3

import sys
from math import *


def prints(_n, _sd, _a, squareMean, _h):
    print("\tNumber of values:\t%d" %(_n))
    print("\tStandard deviation:\t%0.2f" %(_sd))
    print("\tArithmetic mean:\t%0.2f" %(_a))
    print("\tRoot mean square:\t%0.2f" %(squareMean))
    print("\tHarmonic mean:\t\t%0.2f\n" %(_h))


def loop(_n, _a, _h, _sd):
    while (42):
        buff = input("Enter next value: ")

        if (buff == "END"):
            exit(0)

        val = float(buff)
        calc = _n * _a
        squareCalc = (pow(_sd, 2) + pow(_a, 2)) * _n
        _n += 1
        _a = (calc + val) / _n
        _sd = sqrt(((squareCalc + pow(val, 2)) / _n) - pow(_a, 2))
        squareMean = sqrt((squareCalc + pow(val, 2)) / _n)
        _h = _n / ((1 / val) + ((_n - 1) / _h))
        prints(_n, _sd, _a, squareMean, _h)

if __name__ == "__main__":
    try:
        if (len(sys.argv) == 2 and sys.argv[1] == "-h"):
            print("USAGE\n\t./206neutrinos n a h sd\n\nDESCRIPTION\n\tn\tnumber of values\n\ta\tarithmetic mean\n\th\tharminic mean\n\tsd\tstandard deviation")
            exit(0)
        elif (len(sys.argv) == 5):
            _n = float(sys.argv[1])
            _a = float(sys.argv[2])
            _h = float(sys.argv[3])
            _sd = float(sys.argv[4])

            if (_n < 0 or _a < 0 or _h < 0 or _sd < 0):
                print("Bad argument")
                exit(84)

            loop(_n, _a, _h, _sd)
            exit(0)
        else:
            print("Bad argument")
            exit(84)
    except ValueError:
        print("Bad argument")
        exit(84)
