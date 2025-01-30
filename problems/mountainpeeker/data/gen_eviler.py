#!/usr/bin/python3

import sys
import random
import math
rand = random.randint

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        sys.exit(1)
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))

n = int(cmdlinearg('n'))
max_h = int(cmdlinearg('max_h'))
h = rand(int(max_h * 3/4), max_h)
min_x = int(cmdlinearg('min_x'))
max_x = int(cmdlinearg('max_x'))

c = 9.99/10
k = c * max_h / max_x**2
f = lambda i: k * i**2

coords = [(i, int(f(abs(i)) + rand(0, int(max_h * (1 - c))))) for i in range(min_x, max_x + 1) if i != 0]
random.shuffle(coords)

print(n)
print(h)
for i in range(n):
    x = coords[i][0]
    y = coords[i][1]
    assert(x != 0)
    print(f"{x} {y}")
