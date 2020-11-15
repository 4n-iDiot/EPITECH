#!/usr/bin/env python

import sys
from math import *


def prints(ps, ss, p, var, confInt95Sup, confInt95Inf, confInt99Sup, confInt99Inf):
    print("Population size:\t %i" %(int(ps)))
    print("Sample size:\t\t %i" %(int(ss)))
    print("Voting intentions:\t %.2f%%" %(p))
    print("Variance:\t\t %.6f" %(var))
    print("95%% confidence interval: [%.2f%%; %.2f%%]" %(confInt95Inf, confInt95Sup))
    print("99%% confidence interval: [%.2f%%; %.2f%%]" %(confInt99Inf, confInt99Sup))


def poll(ps, ss, p):
    pd = p / 100
    var = ((pd * (1 - pd)) / ss) * ((ps - ss) / (ps - 1))
    confInt95 = 196 * sqrt(var)
    confInt99 = 258 * sqrt(var)
    confInt95Sup = p + confInt95
    confInt95Inf = p - confInt95
    confInt99Sup = p + confInt99
    confInt99Inf = p - confInt99

    if (confInt95Inf < 0):
        confInt95Inf = 0

    if (confInt99Inf < 0):
        confInt99Inf = 0

    if (confInt95Sup > 100):
        confInt95Sup = 100

    if (confInt99Sup > 100):
        confInt99Sup = 100

    prints(ps, ss, p, var, confInt95Sup, confInt95Inf, confInt99Sup, confInt99Inf)


if __name__ == "__main__":
    if (len(sys.argv) == 2 and sys.argv[1] == "-h"):
        print("USAGE\n\t./209poll pSize sSize p\n\nDESCRIPTION\n\tpSize\tsize of the population\n\t"
        "sSize\tsize of the sample (supposed to be representative)\n\tp\tpercentage of voting intentions for a specific candidate")
        exit(0)
    elif(len(sys.argv) == 4):
        try:
            ps = int(sys.argv[1])
            ss = int(sys.argv[2])
            p = float(sys.argv[3])

            if (ps < 0 or ss < 0 or ps < ss or p < 0 or p > 100):
                print("Bad arguments")
                exit(84)

            poll(float(ps), float(ss), p)
            exit(0)
        except ValueError:
                print("Bad arguments")
                exit(84)
    print("Not the right number of arguments")
    exit(84)
