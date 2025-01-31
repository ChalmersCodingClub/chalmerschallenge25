#!/usr/bin/python3
def run(edges):
    M=len(edges) # number of edges
    first_time = True # TODO: determine if first time

    if first_time:
        extra_edges = []
        extra_edges.append([0,1])
        # TODO: add extra edges
        assert len(extra_edges)==30, "Add more edges to the graph!"
        return extra_edges
    else:
        return []
