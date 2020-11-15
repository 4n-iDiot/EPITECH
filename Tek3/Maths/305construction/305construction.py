#!/usr/bin/env python3

import sys
from math import *

# GLOBALS VAR
tasks = []
first_ordered_tasks = []
second_ordered_tasks = []
tot_duration = 0


# PRINTS
def print_res():
    print("Total duration of construction: ", tot_duration, " weeks\n", sep='')
    print_list()
    print(" ")
    print_graph()


def print_list():
    for task in second_ordered_tasks:
        if (task[len(task) - 1] == -1):
            print(task[0], " must begin at t=", task[len(task) - 2], sep='')
        else:
            print(task[0], " must begin between t=", task[len(task) - 2], " and t=", task[len(task) - 1], sep='')


def print_graph():
    for task in second_ordered_tasks:
        if (task[len(task) - 1] == -1):
            int_fluc = 0
        else:
            int_fluc = int(task[len(task) - 1]) - int(task[len(task) - 2])

        print(task[0], "\t(", int_fluc, ")\t", make_graph(task), sep='')


def make_graph(task):
    lign = ""

    for i in range(0, task[len(task) - 2]):
        lign += ' '

    for i in range(int(task[2])):
        lign += '='

    return (lign)



# COMPUTE SEC T
def order_tasks_with_sec_t():
    new_t = []

    for task in second_ordered_tasks:
        new_t.append(find_sec_t(task))

    add_sec_t(new_t)


def add_sec_t(new_t):
    for i in range(len(second_ordered_tasks)):
        second_ordered_tasks[i].append(new_t[i])


def find_sec_t(task):
    task_t = int(task[len(task) - 1])
    task_dur = int(task[2])
    smallest_need_task_t = -1

    for all_task in second_ordered_tasks:
        needed_tasks = get_needed_tasks(all_task)

        if (needed_tasks == []):
            continue

        for need_task in needed_tasks:
            if (task[0] == need_task):
                need_task_t = all_task[len(all_task) - 1]
                if (smallest_need_task_t == -1):
                    smallest_need_task_t = need_task_t
                elif (need_task_t < smallest_need_task_t):
                    smallest_need_task_t = need_task_t

    if (smallest_need_task_t != -1 and ((smallest_need_task_t - task_dur) > task_t)):
        return (smallest_need_task_t - task_dur)
    elif ((smallest_need_task_t == -1) and (tot_duration - task_dur > task_t)):
        return (tot_duration - task_dur)

    return (-1)



# COPUTE T
def find_new_pos_task(new_task):
    i = 0
    new_task_t = int(new_task[len(new_task) - 1])

    for task in second_ordered_tasks:
        task_t = int(task[len(task) - 1])

        if (new_task_t < task_t):
            return (i)

        i += 1

    return (i)


def order_tasks_with_t():
    while(first_ordered_tasks != []):
        for task in first_ordered_tasks:
            if (second_ordered_tasks == []):
                second_ordered_tasks.append(task)
                first_ordered_tasks.remove(task)
            else:
                second_ordered_tasks.insert(find_new_pos_task(task), task)
                first_ordered_tasks.remove(task)


def find_biggest_t(task):
    biggest_t = 0

    for i in range(3, len(task)):
        for task_2 in first_ordered_tasks:
            if (task[i] == task_2[0]):
                task_2_dur = int(task_2[2])
                task_2_t = int(task_2[len(task_2) - 1])
                t = task_2_t + task_2_dur

                if (t >= biggest_t):
                    biggest_t = t

    return (biggest_t)


def compute_t():
    current_t = 0

    for task in first_ordered_tasks:
        task_dur = int(task[2])
        needed_tasks = get_needed_tasks(task)

        if (len(task) == 3):
            task.append(0)
            current_t += task_dur
        elif (len(task) > 3):
            t = find_biggest_t(task)
            task.append(t)
            current_t += task_dur


def compute_tot_duration():
    global tot_duration

    for task in second_ordered_tasks:
        task_t = int(task[len(task) - 1])
        task_dur = int(task[2])
        task_duration = task_t + task_dur

        if (task_duration > tot_duration):
            tot_duration = task_duration



# FIRST ORDER
def order_tasks():
    i = 0
    tasks_done = []

    while (tasks != []):
        for task in tasks:
            if (len(task) == 3):
                first_ordered_tasks.append(task)
                tasks_done.append(task[0])
                tasks.remove(task)
                i += 1
            elif (i != 0 and len(task) > 3):
                res = find_next_tasks(task, tasks_done)

                if (res == True):
                    first_ordered_tasks.append(task)
                    tasks_done.append(task[0])
                    tasks.remove(task)
                    i += 1


def find_next_tasks(task, tasks_done):
    needed_tasks = get_needed_tasks(task)

    for need_task in needed_tasks:
        if (need_task == task[0]):
            print("Unconsistent needed task")
            exit(84)

        if (need_task not in tasks_done):
            return False

    return True


def get_needed_tasks(task):
    needed_tasks = []

    for i in range(3, len(task)):
        if (isinstance(task[i], int)):
            break

        needed_tasks.append(task[i])

    return needed_tasks



# FILE MANAGEMENT
def get_tasks(files):
    try:
        files = open(files, 'r')
    except FileNotFoundError:
        print("File does not exist")
        exit(84)

    file = files.readline()

    while file:
        file = str(file).strip('\n')
        task = file.split(';')
        file = files.readline()
        tasks.append(task)

    check_file()


def check_file():
    for task in tasks:
        if (len(task) < 3 or not task[2].isdigit()):
            print("Bad task")
            exit(84)

    check_needed_tasks()


def check_needed_tasks():
    task_names = []
    needed_tasks = []

    for task in tasks:
        task_names.append(task[0])
        needed_tasks.append(get_needed_tasks(task))

    check_existing_task(task_names, needed_tasks)
    check_needed_tasks_conflict()


def check_needed_tasks_conflict():
    for task in tasks:
        needed_tasks = get_needed_tasks(task)
        for n_task in needed_tasks:
            if (task[0] in get_needed_tasks(get_task(n_task))):
                print("Conflict in needed tasks")
                exit(84)


def check_existing_task(task_names, needed_tasks):
    for i in range(len(tasks)):
        if (needed_tasks[i] == []):
            continue

        for need_tasks in needed_tasks:
            for n_task in need_tasks:
                if (n_task not in task_names):
                    print("Unknown task")
                    exit(84)


def get_task(task_name):
    for task in tasks:
        if (task[0] == task_name):
            return (task)



# MAIN
if __name__ == "__main__":
    try:
        if (len(sys.argv) == 2 and sys.argv[1] == "-h"):
            print("USAGE\n\t./305construction file\n\nDESCRIPTION\n\tfile\tfile describing the tasks")
            exit(0)
        elif (len(sys.argv) == 2):
            get_tasks(sys.argv[1])
            order_tasks()
            compute_t()
            order_tasks_with_t()
            compute_tot_duration()
            order_tasks_with_sec_t()
            print_res()
            exit(0)
    except ValueError:
        print("Bad arguments")

    exit(84)
