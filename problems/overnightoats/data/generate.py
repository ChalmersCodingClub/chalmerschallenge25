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

print(random.randint(1,3))
n = random.randint(1, 100)
print(n)
for _ in range(n):
    a, b = sorted(random.sample([1,2,3], k=2))
    print(a,b)
