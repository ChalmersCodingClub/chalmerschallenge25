#!/usr/bin/python3

import sys
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        exit(1)
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))

letters = "abcdefghijklmnopqrstuvwxyz"
def gen_name():
    x = random.randint(2, 9)
    name = ''.join([random.choice(letters).upper()] + [random.choice(letters) for _ in range(x)])
    p = random.randint(0, 3)
    if p == 0:
        name = "Joshua"
    if p == 1:
        name = "Gustav"
    return name

n = int(cmdlinearg('n'))
m = int(cmdlinearg('m'))
room_size = int(cmdlinearg('room_size'))

names = [gen_name() for _ in range(n)]

print(n, m)
for i in range(n):
    print(names[i], random.randint(0, room_size))
for j in range(m):
    a, b = sorted([random.randint(0,room_size), random.randint(0, room_size)])
    print(a, b)
