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

# room size: (spacing + 1) * (n + 1) - 1
def woven_pattern(n, spacing):
    m = n + 1
    print(n,m)
    for i in range(n):
        print(gen_name(), (spacing + 1) * (i + 1) - 1)
    for i in range(m):
        print((spacing + 1) * i, (spacing + 1) * (i + 1) - 1 - random.randint(0, 1))

n = int(cmdlinearg('n'))
spacing = int(cmdlinearg('spacing'))
assert(spacing >= 1)
woven_pattern(n, spacing)
