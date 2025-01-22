#!/usr/bin/python3

import sys
import random
import itertools as it

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        exit(1)
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
n = int(cmdlinearg('n'))

ranks = ["A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"]
suits = ["C", "S", "D", "H"]
deck = [f"{r}{s}" for r, s in it.product(ranks, suits)]
random.shuffle(deck)

print(n)
print("\n".join(deck[:n]))
