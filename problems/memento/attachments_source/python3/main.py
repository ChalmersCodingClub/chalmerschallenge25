#!/usr/bin/env python3
#
# Testing tool for the task Memento.
# Your solution MUST be named memento.py and placed
# in the same folder as main.py.
#
# Usage:
#
#   python3 main.py [--silent] < seed.txt
#
# input.txt uses the following format:
#
# seed
# Where seed is the seed to be used for all randomness
#
# If --silent is passed, the communication output will not be printed.
#
# The tool is provided as-is, and you should feel free to make
# whatever alterations or augmentations you like to it. Notably,
# this is not the grader used in Kattis. This grader is also more informative
# as to how your program failed compared to Kattis.

import sys
import random

from memento import run

# Exactcly the same as is in the real judge
n=1000
def generate_graph():
    edges = []
    m = random.randint(3500, 4500)

    seen = set()
    for i in range(m):
        a = random.randint(0, n-1)
        b = random.randint(0, n-1)
        if a==b:
            continue
        if (a,b) in seen:
            continue
        seen.add((a,b))
        seen.add((b,a))
        edges.append([a,b])
        continue
    return edges

def main():
    args = sys.argv[1:]

    if args == ["-h"]:
        print("Usage:", sys.argv[0], " ... < input.txt")
        sys.exit(0)
    
    seed = int(input())
    random.seed(seed)

    graph = generate_graph()
    extra_edges = run(graph)
    
    # Sanitize extra edges
    if type(extra_edges) != list:
        print(f"[X] Error: in first phase, gave extra edges that are not a list")
        sys.exit(1)

    if len(extra_edges) == 0:
        print(f"[X] Error: in first phase, thought it had already seen graph")
        sys.exit(1)
    
    if len(extra_edges) != 30:
        print(f"[X] Error: in first phase, number of extra edges is not 30, it is {len(extra_edges)=}")
        sys.exit(1)
    
    for i in range(30):
        e = extra_edges[i]
        if type(e) != list:
            print(f"[X] Error: in first phase, gave an edge that is not a list, {type(e)=}")
            sys.exit(1)
        if len(e)!=2:
            print(f"[X] Error: in first phase, gave edge does not have length 2, {len(e)=}")
            sys.exit(1)
        if type(e[0]) != int or type(e[1]) != int:
            print(f"[X] Error: in first phase, edge indices are not int, {type(e[0])=} {type(e[1])=}")
            sys.exit(1)
        if e[0] < 0 or e[1] < 0 or e[0] >= n or e[1] >= n:
            print(f"[X] Error: in first phase, edge indices are out of bound, {e[0]=} {e[1]=}")
            sys.exit(1)
        if e[0]==e[1]:
            print(f"[X] Error: in first phase, edge indices are equal, {type(e[0])=} {type(e[1])=}")
            sys.exit(1)

    # Shuffle graph
    graph.extend(extra_edges)
    vertex_relabel = [i for i in range(n)]
    random.shuffle(vertex_relabel)
    random.shuffle(graph)
    for i in range(len(graph)):
        graph[i][0] = vertex_relabel[graph[i][0]]
        graph[i][1] = vertex_relabel[graph[i][1]]
        if random.randint(0,1):
            graph[i]=(graph[i][1],graph[i][0])

    res = run(graph)
    if type(extra_edges) != list:
        print(f"[X] Error: in second phase, return value is not a list")
        sys.exit(1)
    if len(res) > 0:
        print(f"[X] Error: in second phase, did not recognize that graph had already been seen")
        sys.exit(1)

    print(f"Success! {seed=}")

if __name__ == "__main__":
    main()
