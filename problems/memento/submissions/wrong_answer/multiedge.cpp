#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;

vector<pair<int, int>> run(vector<pair<int, int>> edges) {
    map<pair<int, int>, int> duplicates;

    for (const auto& e : edges) {
        int u = min(e.first, e.second);
        int v = max(e.first, e.second);
        duplicates[{u, v}] += 1;
    }

    bool first_time = true;
    for (const auto& [key, count] : duplicates) {
        if (count >= 10) {
            first_time = false;
            break;
        }
    }

    if (first_time) {
        vector<pair<int, int>> extra_edges;
        extra_edges.insert(extra_edges.end(), 30, {0, 1});
        assert(extra_edges.size() == 30 && "Add more edges to the graph!");
        return extra_edges;
    } else {
        return {};
    }
}
