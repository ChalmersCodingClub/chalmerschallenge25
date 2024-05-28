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
#define ceildiv(x,y) ((x + y - 1) / (y))

inline void fast() { ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }

#if _LOCAL
#define assert(x) if (!(x)) __debugbreak()
#endif

mt19937 rng((random_device())());
template<typename T, typename U> inline int randint(T lo, U hi) { return uniform_int_distribution<int>((int)lo, (int)hi)(rng); } // [lo,hi]

const int k = 30;
void handle()
{
    const int n = 1000;
    bitset<n*n> edges;
    int m;
    cin >> m;
    vector<p2> graph;
    vi deg(n);
    rep(i, m)
    {
        int a,b;
        cin >> a >> b;
        edges[a*n+b]=1;
        edges[b*n+a]=1;
        deg[a]++;
        deg[b]++;
        graph.emplace_back(a,b);
    }
    vector<p2> nodes;
    rep(i, n) nodes.emplace_back(deg[i], i);
    sort(nodes.rbegin(), nodes.rend());

    
    if (nodes[0].first!=nodes[1].first)
    {
        int cnt = 0;
        int rounds = 1;
        while (rounds<k)
        {
            int s = rounds;
            while (nodes[s].second==nodes[rounds].second)
            {
                cnt += edges[nodes[0].second * n + nodes[s].second];
                s++;
            }
            rounds = s;
        }
        if (cnt>20)
        {
            // NOT first
            cout << "seen before" << endl;
            return;
        }
    }

    cout << "not seen before" << endl;

	int root = nodes[0].second;
	int placed = 0;
	int i = 1;
	while (placed < k)
	{
		if (!edges[root*n+nodes[i].second])
		{
			cout << root << " " << nodes[i].second << endl;
			placed++;
		}
		i++;
	}
}

signed main()
{
    handle();
    handle();
    return 0;
}
