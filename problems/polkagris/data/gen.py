#!/usr/bin/python3

import sys
import random
from random import randrange

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        sys.exit(1)
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))

kind = int(cmdlinearg('kind'))
maxn = int(cmdlinearg('maxn'))
alph = int(cmdlinearg('alph'))

def rand_cane(n):
    cane = []
    while len(cane) < n:
        r = chr(ord('A') + randrange(alph))
        if len(cane) == 0 or r != cane[-1]:
            cane.append(r)
    return "".join(cane)

def unfold_randomly(target):
    initial = target
    while len(initial) < maxn:
        if randrange(2):
            initial = initial + initial[randrange(0,len(initial)):-1][::-1]
        else:
            initial = initial[1:randrange(3,len(initial)+1)][::-1] + initial
    if randrange(2):
        return initial[:maxn]
    else:
        return initial[-maxn:]

def gen():
    if kind == 1:
        return "Q", "Q"
    elif kind == 2:
        return "".join(["UC"[i%2] for i in range(maxn)]), "UC"
    elif kind == 3:
        return "".join(["UC"[i%2] for i in range(maxn)]), "CU"
    elif kind == 4: # Randomly unfolded
        target = rand_cane(10)
        initial = unfold_randomly(target)
        return initial, target
    elif kind == 5: # Randomly unfolded, plus a swap
        target = rand_cane(10)
        initial = unfold_randomly(target)
        while True:
            initial2 = list(initial)
            a = randrange(1,len(initial)-1)
            b = randrange(1,len(initial)-1)
            initial2[a], initial2[b] = initial2[b], initial2[a]
            if (initial2[a-1] != initial2[a] != initial2[a+1] and
                initial2[b-1] != initial2[b] != initial2[b+1]):
                initial = "".join(initial2)
                break
        return initial, target
    elif kind == 6:
        initial = rand_cane(randrange(maxn//2,maxn))
        l = randrange(len(initial)-1)
        r = min(randrange(l, len(initial)) for _ in range(2))
        target = initial[l:r+1]
        return initial, target
    elif kind == 7:
        initial = ["UC"[i%2] for i in range(maxn)]
        initial[randrange(maxn//10)] = "H"
        initial[maxn*9//10+randrange(maxn//10)] = "H"
        return "".join(initial), "UC"
    else:
        raise Exception("unreachable")

initial, target = gen()
print(len(initial), len(target))
print(initial)
print(target)
