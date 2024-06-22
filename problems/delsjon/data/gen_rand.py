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

# Stolen from https://github.com/cheran-senthil/PyRival/blob/master/pyrival/data_structures/DisjointSetUnion.py
class UF:
    def __init__(self, n):
        self.parent = list(range(n))

    def find(self, a):
        acopy = a
        while a != self.parent[a]:
            a = self.parent[a]
        while acopy != a:
            self.parent[acopy], acopy = a, self.parent[acopy]
        return a

    def union(self, a, b):
        self.parent[self.find(b)] = self.find(a)

uf = UF(n)

edges = []

for i in range(n-1):
    while True:
        a,b=rand(0,n-1),rand(0,n-1)
        if a==b:continue
        if uf.find(a)==uf.find(b):continue
        uf.union(a,b)
        edges.append((a+1,b+1))
        break

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
