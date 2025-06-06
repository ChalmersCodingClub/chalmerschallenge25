#!/usr/bin/env python3
import os
import sys
import random

from memento import run



def main():
    _USER_FAIL = 120
    _SECRET_FAIL = "FAILwerhiuwehruiwehuriphwer"
    _SECRET_KEY = "SUCCESSlmwnerhbiwerhuebifi"

    n = 1000
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

    seed = int(input())
    random.seed(seed)
    edges = generate_graph()

    r, w = os.pipe()
    pid = os.fork()

    if pid == 0:
        os.close(r)
        w = os.fdopen(w, 'w')
        
        res = run(edges)
        if type(res) != list:
            print(f"{_SECRET_FAIL}Did not give 30 edges in first round")
            sys.exit(_USER_FAIL)
        if len(res) != 30:
            print(f"{_SECRET_FAIL}Did not give 30 edges in first round")
            sys.exit(_USER_FAIL)
        
        for i in range(30):
            e = res[i]
            if type(e) != list:
                print(f"{_SECRET_FAIL}Gave invalid edge in first round")
                sys.exit(_USER_FAIL)
            if len(e)!=2:
                print(f"{_SECRET_FAIL}Gave invalid edge in first round")
                sys.exit(_USER_FAIL)
            if type(e[0]) != int or type(e[1]) != int:
                print(f"{_SECRET_FAIL}Gave invalid edge in first round")
                sys.exit(_USER_FAIL)
            if e[0] < 0 or e[1] < 0 or e[0] >= n or e[1] >= n:
                print(f"{_SECRET_FAIL}Gave invalid edge in first round")
                sys.exit(_USER_FAIL)
            if e[0]==e[1]:
                print(f"{_SECRET_FAIL}Gave invalid edge in first round")
                sys.exit(_USER_FAIL)
            a,b = e[0],e[1]
            if [a,b] in edges or [b,a] in edges:
                print(f"[X] Error: in first phase, gave edge that already exists, {e[0]=} {e[1]=}")
                sys.exit(_USER_FAIL)
            edges.append([a,b])

        for e in res:
            w.write(f"{e[0]}${e[1]}@")

        w.close()
    else:
        os.close(w)
        r = os.fdopen(r)
        pid, status = os.waitpid(pid, 0)
        if os.WIFSIGNALED(status): os.kill(pid, os.WTERMSIG(status))
        ex = os.WEXITSTATUS(status)
        if ex == _USER_FAIL: sys.exit(0)
        if ex != 0: sys.exit(ex)
        buf = r.read()
        buf = [[int(i) for i in ed.split("$")] for ed in buf.split("@")[:-1]]
        
        edges.extend(buf)

        vertex_relabel = [i for i in range(n)]
        random.shuffle(vertex_relabel)
        random.shuffle(edges)
        for i in range(len(edges)):
            edges[i][0] = vertex_relabel[edges[i][0]]
            edges[i][1] = vertex_relabel[edges[i][1]]
            if random.randint(0,1):
                edges[i]=[edges[i][1],edges[i][0]]

        res = run(edges)
        if type(res) != list:
            print(f"{_SECRET_FAIL}Gave invalid response in second round")
            sys.exit(_USER_FAIL)
        if len(res) > 0:
            print(f"{_SECRET_FAIL}Did not recognize it had already seen graph in second round")
            sys.exit(0)

        print(_SECRET_KEY + str(seed))

if __name__ == "__main__":
    main()
