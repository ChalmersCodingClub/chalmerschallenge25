def run(edges_in):
    M = len(edges_in)
    edges = set()
    deg = [0]*1000
    for i in range(M):
        a,b = edges_in[i]
        if a > b: a,b=b,a
        edges.add((a, b))
        deg[a] += 1
        deg[b] += 1

    if max(deg) >= 38:
        return []

    u = 0
    while deg[u] < 8:
        u += 1

    ret = []
    v = -1
    p = 0
    while p < 30:
        v += 1
        if v == u: continue
        if (v,u) in edges or (u,v) in edges: continue
        ret.append((u,v))
        p += 1
    return ret
