#!/usr/bin/env python3
import random

print_graph = False

if __name__ == "__main__":
    seen = set()
    n = 1000
    m = random.randint(2500, 3500)
    if print_graph:
        print(m)
    
    for i in range(m):
        while True:
            a = random.randint(0, n-1)
            b = random.randint(0, n-1)
            if a == b or (a,b) in seen:
                continue
            # Since graph is undirected
            seen.add((a,b))
            seen.add((b,a))
            print(a, b)
            break
