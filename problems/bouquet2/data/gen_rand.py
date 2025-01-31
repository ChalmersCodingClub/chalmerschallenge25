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

r = int(cmdlinearg('r'))
g = int(cmdlinearg('g'))
b = int(cmdlinearg('b'))
min_x = int(cmdlinearg('min_x', -1000000000))
max_x = int(cmdlinearg('max_x',  1000000000))
min_y = int(cmdlinearg('min_y', -1000000000))
max_y = int(cmdlinearg('max_y',  1000000000))
min_dist = int(cmdlinearg('min_dist', -1))

flowers = []
used_positions = set()
for c,cnt in zip("RGB", [r,g,b]):
    for i in range(cnt):
        p = None
        while p is None or p in used_positions or p[0]**2+p[1]**2 < min_dist**2:
            p = (random.randint(min_x, max_x), random.randint(min_y, max_y))
        used_positions.add(p)
        flowers.append((*p, c))
random.shuffle(flowers)

print(r+g+b)
for f in flowers:
    print(*f)
