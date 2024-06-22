#!/usr/bin/python3

import sys
import random
import math
from random import randint as rand
import subprocess

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
l = int(cmdlinearg("l"))

edges = []

ind = 2
while len(edges)<n-l-1:
    edges.append((ind-1,ind))
    ind += 1

while len(edges)<n-1:
    edges.append((ind, rand(1, ind-1)))
    ind+=1

data = str(n)+"\n"
for e in edges:
    data += f"{e[0]} {e[1]}\n"


process = subprocess.Popen(
    ['./a.out'],  # Path to the executable
    stdin=subprocess.PIPE,  # Enable input redirection
    stdout=subprocess.PIPE,  # Enable output redirection
    stderr=subprocess.PIPE,  # Enable error redirection (optional)
    text=True  # Enable text mode for easier string input/output handling
)

# Send input to the C++ program and get the output
stdout, stderr = process.communicate(input=data)
print(stdout,end="")
