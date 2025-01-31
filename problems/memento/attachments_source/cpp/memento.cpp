#include <vector>
#include <cassert>
#include "memento.h"

std::vector<std::pair<int,int>> run(std::vector<std::pair<int,int>> edges)
{
    int M=edges.size(); // number of edges
    bool first_time = true; // TODO: determine if first time

    if (first_time)
    {
        std::vector<std::pair<int,int>> extra_edges = {};
        extra_edges.emplace_back(0,1);
        // TODO: add extra edges
        assert(extra_edges.size()==30 && "Add more edges to the graph!");
        return extra_edges;
    }
    else
    {
        return {};
    }
}

