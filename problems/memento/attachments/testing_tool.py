#!/usr/bin/env python3
#
# Testing tool for the task KATT:s and rats.
#
# Usage:
#
#   python3 testing_tool.py [--silent] program... < input.txt
#
# input.txt uses the following format:
#
# N K
# S
# l r
# Where N is the length of S,
# K is the maximum length of a message that the encoder may produce,
# S is the message that should be sent,
# l and r denote the interval that should be flipped.
# More precisely, the judge will flip m[l], m[l+1], ..., m[r]
#
#
# For example, if you have a Python solution that you would run using
# "python3 file.py", you could invoke the testing tool with:
#
#   python3 testing_tool.py python3 file.py < input.txt
#
# where input.txt is a file that contains e.g.
#
# 5 10
# 01011
# 1 3
#
#
#
# This input corresponds to sample case 1.
# If --silent is passed, the communication output will not be printed.
#
# The tool is provided as-is, and you should feel free to make
# whatever alterations or augmentations you like to it. Notably,
# this is not the grader used in Kattis.

import subprocess
import sys

def error(msg):
    print("ERROR:", msg)
    sys.exit(1)

def main():
    silent = False
    args = sys.argv[1:]
    if args and args[0] == "--silent":
        args = args[1:]
        silent = True
    if not args or args == ["--help"] or args == ["-h"]:
        print("Usage:", sys.argv[0], "[--silent] program... <input.txt")
        sys.exit(0)
    
    try:
        n, k = [int(i) for i in input().split()]
        s = input()
        l, r = [int(i) for i in input().split()]
    except Exception:
        error("bad input format: failed to parse first line as two integers")

    assert(len(s)==n, f"The length of s, {len(s)=} did not match {n=}")
    assert(k>n, f"{k=} must be greater than {n=}")

                
    proc = subprocess.Popen(args, stdin=subprocess.PIPE, stdout=subprocess.PIPE)
    if not silent:
        print(f"[*] Running with N = {n}, K = {k}, S = {s}")

    proc.stdin.write(f"{n} {k}\n".encode("utf8"))
    proc.stdin.flush()

    rs = " ".join([str(i+1) for i in sorted(rats)]) + "\n"
    ts = " ".join([str(i+1) for i in sorted(targets)]) + "\n"
    proc.stdin.write(rs.encode("utf8"))
    proc.stdin.flush()
    proc.stdin.write(ts.encode("utf8"))
    proc.stdin.flush()
    if not silent:
        print(f"< {n} {k}")
        print("<",rs, end="")
        print("<",ts, end="")

    MAX_QUERIES = 25000
    queries = 0

    while True:
        command = proc.stdout.readline().decode("utf8")
        command = command.strip()
        line = command

        if queries > MAX_QUERIES:
            error("[*] Wrong answer: Too many queries")

        if not silent:
            print(f"> {command}")

        if command == "activate!":
            if set(rats) == set(targets):
                print(f"[*] OK: Caught all rats. queries used: {queries}.")
                exit(0)
            else:
                error("f[*] Wrong answer: Activated traps while not all rats caught.")

        queries += 1
        try:
            command = [int(i) for i in command.split()]
            M = command[0]
            sonar = command[1:]
            sonar = [int(i)-1 for i in sonar]
            assert(len(sonar) == M)
            assert(len(sonar) == len(set(sonar)))
            assert(all([0 <= x < n for x in sonar]))
        except:
            error(f"Invalid query: '{line}'")
                

        dist = [-1] * n
        queue = []
        for r in sonar:
            dist[r] = 0
            queue.append(r)
            

        while queue:
            x = queue.pop(0)
            for nei in g[x]:
                if dist[nei] == -1:
                    dist[nei] = dist[x] + 1
                    queue.append(nei)

        occupied = [False]*n
        for r in rats:
            occupied[r] = True
        for r in sorted(rats):
            best_score = dist[r]
            best = r
            for nei in g[r]:
                if occupied[nei]: continue
                if (dist[nei] > best_score) or (dist[nei] == best_score and nei < best and best != r):
                    best = nei
                    best_score = dist[nei]
            occupied[r] = False
            occupied[best] = True

        rats = [r for r in range(n) if occupied[r]]
        rs = " ".join([str(i+1) for i in sorted(rats)]) + "\n"
        
        proc.stdin.write(rs.encode("utf8"))
        proc.stdin.flush()
        if not silent:
            print("<",rs, end="")
        

if __name__ == "__main__":
    main()