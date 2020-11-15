#!/usr/bin/env python3

import sys
from math import *

nums = []


def check_if_done(array):
    prec = float(array[0])

    for arr in range(len(array)):
        if (float(array[arr]) < float(prec)):
            return (False)

        prec = float(array[arr])

    return (True)


def selection_sort(array):
    comparison = 0
    i = 0

    while (check_if_done(array) != True):
        for arr in range(i + 1, len(array)):
            comparison += 1
            if (float(array[arr]) <= float(array[i])):
                array[arr], array[i] = array[i], array[arr]

        i += 1

    if (comparison == 0):
        comparison = len(array) - 1

    return (comparison)


def insertion_sort(array):
    i = 1
    comparison = 0

    while (i != len(array)):
        for arr in range(0, i):
            comparison += 1
            if (float(array[arr]) > float(array[i])):
                array.insert(arr, array[i])
                array.pop(i + 1)
                break

        i += 1

    return (comparison)


def bubble_sort(array):
    i = 1
    comparison = 0

    for j in range(len(array)):
        for arr in range(len(array) - i):
            comparison += 1
            if (float(array[arr]) > float(array[arr + 1])):
                array[arr], array[arr + 1] = array[arr + 1], array[arr]

        i += 1

    return (comparison)


def quick_sort(array):
    if (len(array) < 2):
        return (0)

    comparison = 0
    list_left = []
    list_right = []

    for i in range(len(array)):
        if (i != 0):
            comparison += 1
            if (float(array[i]) < float(array[0])):
                list_left.append(float(array[i]))

            if (float(array[i]) >= float(array[0])):
                list_right.append(float(array[i]))

    comparison += quick_sort(list_left)
    comparison += quick_sort(list_right)

    return (comparison)


def check_if_number():
    global nums

    for num in nums:
        try:
            num = float(num)
        except ValueError:
            print("Not a number")
            exit(84)


def get_nums(file):
    global nums

    try:
        file = open(file, 'r')
    except FileNotFoundError:
        exit(84)

    nums = file.read()

    if (len(nums) == 0):
        exit(84)

    nums = nums.split()
    check_if_number()


if __name__ == "__main__":
    try:
        if (len(sys.argv) == 2 and sys.argv[1] == "-h"):
            print("USAGE\n\t./301dannon file\n\nDESCRIPTION\n\tfile\tfile that contains the numbers to be sorted, seperated by spaces")
            exit(0)
        elif (len(sys.argv) == 2):
            get_nums(sys.argv[1])

            if (len(nums) > 1):
                print(len(nums), "elements")
            else:
                print(len(nums), "element")

            print("Selection sort:", selection_sort(nums.copy()), "comparisons")
            print("Insertion sort:", insertion_sort(nums.copy()), "comparisons")
            print("Bubble sort:", bubble_sort(nums.copy()), "comparisons")
            print("Quicksort:", quick_sort(nums.copy()), "comparisons")
            exit(0)
    except ValueError:
        print("Bad argument")
    exit(84)
