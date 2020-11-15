#!/usr/bin/env python3

import sys
import time
from math import *


def binomialLaw(_d):
    start_time = time.time()
    _n = 3500
    _k = 0
    p = _d / (3600 * 8)
    overload = 0

    print("Binomial distribution:", end="")

    while (_k <= 50):

        bino = coefBinomiaux(_n, _k) * pow(p, _k) * (pow((1 - p), (_n - _k)))

        if ((_k % 6) == 0):
            print("\n", end="")

        print("%d -> %0.3f\t" %(_k, bino), end="")

        if (_k > 25):
            overload += bino

        _k += 1

    print("\noverload: %0.1f%%" %(overload * 100))
    print("computation time: %0.2f ms\n" %(time.time() - start_time))


def poissonLaw(_d):
    start_time = time.time()
    _k = 0
    lamb = 3500 * (_d / (3600 * 8))
    overload = 0

    print("Poisson distribution:", end="")

    while (_k <= 50):
        poisson = (pow(lamb, _k) / factorial(_k)) * exp(-lamb)

        if ((_k % 6) == 0):
            print("\n", end="")

        print("%d -> %.3f\t" %(_k, poisson), end="")

        if (_k > 25):
            overload += poisson

        _k += 1

    print("\noverload: %0.1f%%" %(overload * 100))
    print("computation time: %0.2f ms" %(time.time() - start_time))


def coefBinomiaux(_n, _k):
    res = (factorial(_n) // (factorial(_k) * factorial(_n - _k)))

    return (res)


if (len(sys.argv) == 2 or len(sys.argv) == 3):
    try:
        if (len(sys.argv) == 2):
            if (sys.argv[1] == "-h"):
                print("USAGE\n\t./203hotline [n k | d]\n\nDESCRIPTION\n\tn\tn value for the computation of (n k)\n\tk\tk value for the computation of (n k)\n\td\taverage duration of calls (in seconds)")
                exit(0)

            _d = float(sys.argv[1])

            binomialLaw(_d)
            poissonLaw(_d)
            exit(0)
        elif (len(sys.argv) == 3):
            _n = int(sys.argv[1])
            _k = int(sys.argv[2])

            print("%d-combination of a %d set:\n%d" %(_k, _n, coefBinomiaux(_n, _k)))

            exit(0)
    except ValueError:
        exit(84)
exit(84)
