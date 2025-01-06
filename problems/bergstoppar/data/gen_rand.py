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
h = rand(0, max_h)
min_x = int(cmdlinearg('min_x'))
max_x = int(cmdlinearg('max_x'))

coords = [(i, rand(0, max_h)) for i in range(min_x, max_x + 1) if i != 0]
random.shuffle(coords)

print(n)
print(h)
for i in range(n):
    print(f"{coords[i][0]} {coords[i][1]}")
