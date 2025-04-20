#!/usr/bin/python3
def run(edges):
    out_from = {i:0 for i in range(1000)}
    s_edges = set()
    for e in edges:
        s_edges.add(tuple(e) if e[0] < e[1] else (e[1], e[0]))
        out_from[e[0]] += 1
        out_from[e[1]] += 1

    biggest_val, biggest_win = 0, -1
    for i in range(1000):
        if out_from[i] > biggest_val:
            biggest_val = out_from[i]
            chosen = i

    if biggest_val > 35:
        return []


    extra_edges = set()
    added = 0
    trys = 1
    while added < 30:
        to = (chosen+trys)%1000
        adds = (chosen, to) if chosen < to else (to, chosen)

        if not (adds in s_edges or adds in extra_edges):
            extra_edges.add(adds)
            added += 1

        trys += 1

    extra_edges = [list(e) for e in extra_edges]
    return extra_edges