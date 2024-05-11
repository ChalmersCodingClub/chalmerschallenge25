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
nums = [i+1 for i in range(n)]
nums = list(reversed(nums))
for i in range(10):
    a = rand(0,n-1)
    b = rand(0,n-1)
    nums[a],nums[b]=nums[b],nums[a]
print(n)
print(*nums)
