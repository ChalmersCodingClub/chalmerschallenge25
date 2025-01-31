import sys
import random

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

n = random.randint(1, maxn)
x = random.randint(1, 10) if random.randint(0,1) else random.randint(1,maxn)
arr = []
if kind == 1:
    arr = ["PASS"] * n
elif kind == 2:
    n = n // 2 * 2
    arr = ["ADD","EAT"] * (n//2)
elif kind == 3:
    x = min(x, n//2)
    arr = ((["ADD"] * x +  ["EAT"] * x) * (n//(2*x)))
    while len(arr) < n: arr.append("PASS")
else:
    k = maxn//4
    n = 4*k
    x = 2*k
    arr = ["ADD"]*k + ["ADD","EAT"]*k + ["EAT"]*k

print(n)
print(x)
for a in arr:
    print(a)
