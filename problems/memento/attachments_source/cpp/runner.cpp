// Testing tool for the task Memento.
//
// Usage:
//
//   bash unix_compile.sh
//   bash unix_run.sh
//
// input.txt uses the following format:
//
// seed
// Where seed is the seed to be used for all randomness
//
// The tool is provided as-is, and you should feel free to make
// whatever alterations or augmentations you like to it. Notably,
// this is not the grader used in Kattis. This grader is also more informative
// as to how your program failed compared to Kattis.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <random>
#include <set>
#include <algorithm>
#include <tuple>

using namespace std;

#include "memento.h"

const int n = 1000;
vector<pair<int,int>> generate_graph(mt19937& rng)
{
    vector<pair<int,int>> ret;
    uniform_int_distribution<int> m_dist(3500, 4500);
	uniform_int_distribution<int> node_dist(0, n-1);
    int m = m_dist(rng);

    set<pair<int,int>> seen;
    for (int i = 0; i < m; i++)
    {
        while (true)
        {
            int a = node_dist(rng);
            int b = node_dist(rng);
            if (a==b) continue;
            if (seen.find(pair<int,int>(a,b))!=seen.end()) continue;
            seen.insert(pair<int,int>(a,b));
            seen.insert(pair<int,int>(b,a));
            ret.emplace_back(a,b);
            break;
        }
    }
    return ret;
}

vector<pair<int,int>> shuffle_graph(vector<pair<int,int>> graph, mt19937& rng)
{
    vector<int> permute(n);
    for (int i = 0; i < n; i++) permute[i] = i;
    shuffle(permute.begin(), permute.end(), rng);
    shuffle(graph.begin(), graph.end(), rng);
    uniform_int_distribution<int> bool_dist(0, 1);
    for (int i = 0; i < graph.size(); i++)
    {
        graph[i].first = permute[graph[i].first];
        graph[i].second = permute[graph[i].second];
        if (bool_dist(rng)) swap(graph[i].first, graph[i].second); 
    }
    return graph;
}


int main(int argc, char* argv[]) {
    if (argc > 1 && string(argv[1]) == "-h") {
        cout << "Usage: program < input.txt" << endl;
        return 0;
    }

    int seed;
    cin >> seed;
    mt19937 rng(seed);

    vector<pair<int,int>> graph = generate_graph(rng);
    vector<pair<int,int>> extra_edges = run(graph);
    
    if (extra_edges.empty()) {
        cerr << "[X] Error: in first phase, thought it had already seen graph" << endl;
        return 1;
    }
    if (extra_edges.size() != 30) {
        cerr << "[X] Error: in first phase, number of extra edges is not 30, it is " << extra_edges.size() << endl;
        return 1;
    }

    for (int i = 0; i < 30; i++)
    {
        int a,b;
        tie(a,b) = extra_edges[i];
        if (a<0||b<0||a>=n||b>=n)
        {
            cerr << "[X] Error: in first phase, edge indices are out of bound, " << a << " " << b << endl;
            return 1;
        }
        if (a==b)
        {
            cerr << "[X] Error: in first phase, edge indices are equal, " << a << " " << b << endl;
            return 1;
        }
        if (find(graph.begin(), graph.end(), pair<int,int>(a,b))!=graph.end() || find(graph.begin(), graph.end(), pair<int,int>(b,a))!=graph.end())
        {
            cerr << "[X] Error: in first phase, gave edge that already exists: " << a << " " << b << endl;
            return 1;
        }
        graph.emplace_back(a,b);
    }

    for (auto e : extra_edges)
    {
        graph.push_back(e);
    }
    graph = shuffle_graph(graph, rng);

    graph = run(graph);
    if (graph.size())
    {
        cerr << "[X] Error: in second phase, did not recognize that graph had already been seen" << endl;
        return 1;
    }

    cout << "Success! seed=" << seed << endl;
    return 0;
}
