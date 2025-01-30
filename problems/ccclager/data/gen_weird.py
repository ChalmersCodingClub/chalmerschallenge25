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

used_names = set()
letters = "abcdefghijklmnopqrstuvwxyz"
def gen_name():
    x = random.randint(3, 10)
    name = ''.join([random.choice(letters).upper()] + [random.choice(letters) for _ in range(x-1)])
    while name in used_names:
        x = random.randint(3, 10)
        name = ''.join([random.choice(letters).upper()] + [random.choice(letters) for _ in range(x-1)])
    used_names.add(name)
    return name

# room size: (spacing + 1) * (n + 1) - 1
def woven_pattern(n, spacing):
    names = []
    if random.randint(0,1):
        names.append("Joshua")
        used_names.add("Joshua")

    if random.randint(0,1) and len(names) < n:
        names.append("Gustav")
        used_names.add("Gustav")

    if len(names) < n:
        names.extend(gen_name() for _ in range(n - len(names)))

    m = n + 1
    print(n,m)
    for i in range(n):
        print(names[i], (spacing + 1) * (i + 1) - 1)
    for i in range(m):
        print((spacing + 1) * i, (spacing + 1) * (i + 1) - 1 - random.randint(0, 1))

n = int(cmdlinearg('n'))
spacing = int(cmdlinearg('spacing'))
assert(spacing >= 1)
woven_pattern(n, spacing)
