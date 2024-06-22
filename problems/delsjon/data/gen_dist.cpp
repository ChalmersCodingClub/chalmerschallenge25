#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
const int inf = int(1e18);

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> p2;

#define rep(i, high) for (int i = 0; i < high; i++)
#define repp(i, low, high) for (int i = low; i < high; i++)
#define repe(i, container) for (auto& i : container)
#define sz(container) ((int)container.size())
#define all(x) begin(x),end(x)
#define ceildiv(x,y) (((x) + (y) - 1) / (y))

inline void fast() { ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }

#if _LOCAL
#define assert(x) if (!(x)) __debugbreak()
#endif

struct UF
{
    vi par;
    vi size;
    UF(int n) : par(n), size(n,1)
    {
        rep(i,n) par[i]=i;
    }
    int find(int x) {return par[x]==x?x:par[x]=find(par[x]);}
    int merge(int a, int b)
    {
        a =find(a); b=find(b);
        if (a==b) return 0;
        if (size[a]<size[b]) swap(a,b);
        par[b]=a;
        size[a]+=size[b];
        return 1;
    }
};

signed main()
{
    fast();

    int n;
    cin >> n;
    vvi edges(n);
    vi deg(n);
    UF uf(n);
    rep(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
        assert(uf.merge(a,b));
        deg[a]++;
        deg[b]++;
    }

    int num_leaf = 0;
    vi ind(n);
    rep(i, n) if (deg[i] == 1) ind[i]=num_leaf++;
    vvi dist(num_leaf, vi(num_leaf));

    rep(i, n)
    {
        if (deg[i] > 1)continue;
        queue<p2> q;
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

            repe(e, edges[u])
            {
                q.emplace(d + 1, e);
            }
        }
    }

    cout << num_leaf << "\n";
    rep(i, num_leaf)
    {
        rep(j, num_leaf)
        {
            cout << dist[i][j];
            if (j!=num_leaf-1) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}
