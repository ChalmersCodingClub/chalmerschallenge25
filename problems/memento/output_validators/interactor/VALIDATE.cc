#include "validate.h"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

auto Start = chrono::high_resolution_clock::now();
void resettimer() { Start = chrono::high_resolution_clock::now(); }
int elapsedmillis() { return chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - Start).count(); }

int n = 1000;
uniform_int_distribution<int> node_dist(0, n-1);
mt19937 rng;
vector<pii> generate_graph()
{
    vector<pii> ret;
    uniform_int_distribution<int> m_dist(2500, 3500);
    int m = m_dist(rng);

    set<pii> seen;
    for (int i = 0; i < m; i++)
    {
        while (true)
        {
            int a = node_dist(rng);
            int b = node_dist(rng);
            if (a==b) continue;
            if (seen.find(pii(a,b))!=seen.end()) continue;
            seen.insert(pii(a,b));
            seen.insert(pii(b,a));
            ret.emplace_back(a,b);
            break;
        }
    }
    return ret;
}

vector<pii> communicate(vector<pii> graph, bool first)
{
    cout << graph.size() << endl;
    for (int i = 0; i < sz(graph); i++)
    {
        cout << graph[i].first << " " << graph[i].second << endl;
    }

    // mixing getline and normal cin is troublesome
    vector<string> response(3);
    if (!(cin >> response[0])) wrong_answer("needed more output");
    if (!(cin >> response[1])) wrong_answer("needed more output");
    if (response[0]=="not")
    {
        if (!(cin >> response[2])) wrong_answer("needed more output");
    }

    if (first)
    {
        if (response[0]=="not" && response[1]=="seen" && response[2]=="before")
        {
            set<pii> seen;
            for (auto e : graph)
            {
                seen.insert(pii(e.first,e.second));
                seen.insert(pii(e.second,e.first));
            }

            for (int i = 0; i < 30; i++)
            {
                int a,b;
                if (!(cin >> a >> b)) wrong_answer("Did not get 30 edges");
                if (a < 0 || a > 999 || b < 0 || b > 999) wrong_answer("Edge nodes out of range");
                if (a==b) wrong_answer("Edge from a to a (loops) not allowed");
                if (seen.find(pii(a,b))!=seen.end()) wrong_answer("Edge not unique");
                if (seen.find(pii(b,a))!=seen.end()) wrong_answer("Edge not unique");
                seen.insert(pii(a,b));
                seen.insert(pii(b,a));
                graph.emplace_back(a,b);
            }

            return graph;
        }
        else
        {
            wrong_answer("Thought it had seen graph before");
        }
    }
    else
    {
        if (response[0]=="not" && response[1]=="seen" && response[2]=="before") wrong_answer("did not recognize graph");
        else if (response[0]=="seen" && response[1]=="before")
        {
            accept();
        }
        else
        {
            wrong_answer("unknown response");
        }
    }
}

vector<pii> shuffle_graph(vector<pii> graph)
{
    vi permute(1000);
    rep(i, 0, 1000) permute[i] = i;
    shuffle(permute.begin(), permute.end(), rng);
    shuffle(graph.begin(), graph.end(), rng);
    uniform_int_distribution<int> bool_dist(0, 1);
    for (int i = 0; i < sz(graph); i++)
    {
        graph[i].first = permute[graph[i].first];
        graph[i].second = permute[graph[i].second];
        if (bool_dist(rng)) swap(graph[i].first, graph[i].second); 
    }
    return graph;
}

int main(int argc, char **argv) {
    init_io(argc, argv);

    int seed;
    judge_in >> seed;
    rng = mt19937(seed);

    vector<pii> graph = generate_graph();

    vector<pii> new_graph = communicate(graph, true);
    new_graph = shuffle_graph(new_graph);
    communicate(new_graph, false);
    return 0;
}
