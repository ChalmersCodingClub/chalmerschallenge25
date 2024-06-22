#include "validate.h"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

int MAX_NODES = 2000;

struct UF
{
    vi par;
    vi size;
    UF(int n) : par(n), size(n,1)
    {
        rep(i,0,n) par[i]=i;
    }
    int find(int x) {return par[x]==x?x:par[x]=find(par[x]);}
    int merge(int a, int b)
    {
        a = find(a); b = find(b);
        if (a==b) return 0;
        if (size[a]<size[b]) swap(a,b);
        par[b]=a;
        size[a]+=size[b];
        return 1;
    }
};

vector<vi> compute_distances(int n, vector<pii> edge_in)
{
    vector<vi> edges(n);
    vi deg(n);
    rep(i, 0, n - 1)
    {
        int a, b;
        tie(a,b)=edge_in[i];
        edges[a].push_back(b);
        edges[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }

    int num_leaf = 0;
    vi ind(n);
    rep(i, 0, n) if (deg[i] == 1) ind[i]=num_leaf++;
    vector<vi> dist(num_leaf, vi(num_leaf));

    rep(i, 0, n)
    {
        if (deg[i] > 1)continue;
        queue<pii> q;
        q.emplace(0, i);
        vi vis(n);
        while (q.size())
        {
            int d, u;
            tie(d, u) = q.front();
            q.pop();

            if (vis[u]) continue;
            vis[u] = 1;

            if (deg[u] == 1)dist[ind[i]][ind[u]] = d;

            for (auto e : edges[u])
            {
                q.emplace(d + 1, e);
            }
        }
    }
    return dist;
}

int main(int argc, char **argv)
{
    init_io(argc, argv);

    int k;
    judge_in >> k;

    vector<vi> dist(k, vi(k));
    rep(i,0,k) rep(j,0,k) judge_in >> dist[i][j];

    auto check = [&](istream& sol, feedback_function feedback)
    {
        int node_cnt;
        if(!(sol >> node_cnt)) feedback("Expected more output");
        if (node_cnt < k) feedback("Not enough nodes");
        if (node_cnt > MAX_NODES) feedback("Too many nodes");
        vector<pii> edges;
        UF uf(node_cnt);
        vi deg(node_cnt);
        rep(i,0,node_cnt-1)
        {
            int a,b;
            if (!(sol >> a >> b)) feedback("Expected more output");
            if (a < 1 || a > node_cnt || b < 1 || b > node_cnt) feedback("Vertices out of range");
            a--; b--;
            if (!uf.merge(a,b)) feedback("Edges do not form tree");
            edges.emplace_back(a,b);
            deg[a]++;
            deg[b]++;
        }

        rep(i,0,k)
        {
            if (deg[i]!=1) feedback("Some node in [1, k] was not leaf");
        }
        rep(i,k,node_cnt)
        {
            if (deg[i]==1) feedback("Some node in [k+1, n] was leaf");
        }
        vector<vi> sol_distances = compute_distances(node_cnt, edges);
        assert(sz(sol_distances)==k);
        if (sol_distances!=dist) feedback("Distances of output do not match input");

        string trailing;
        if(sol >> trailing) feedback("Trailing output");
        return true;
    };

    bool judge_found_sol = check(judge_ans, judge_error);
    bool author_found_sol = check(author_out, wrong_answer);

    if (!judge_found_sol)
        judge_error("NO! Judge failed to find solution");

    if (!author_found_sol)
        wrong_answer("Contestant failed to find solution");

    accept();
}
