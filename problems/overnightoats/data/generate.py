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

p = float(cmdlinearg('p'))
x = int(cmdlinearg("x"))
g = int(cmdlinearg("g"))

n = random.randint(1, 100_000)
arr = ["PASS"] * n
for _ in range(int(p*n)):
    a = random.randrange(n)
    b = min(a + random.randint(1, x+g), n-1)
    if a != b and arr[a] == "PASS" and arr[b] == "PASS":
        arr[a] = "ADD"
        arr[b] = "EAT"

print(n)
print(x)
for a in arr:
    print(a)
