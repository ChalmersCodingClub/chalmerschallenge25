#include <bits/stdc++.h>
#include <bits/extc++.h>
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

auto Start = chrono::high_resolution_clock::now();
void resettimer() { Start = chrono::high_resolution_clock::now(); }
int elapsedmillis() { return chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - Start).count(); }

#if _LOCAL
#define assert(x) if (!(x)) __debugbreak()
#endif


const ll INF = numeric_limits<ll>::max() / 4;

struct MCMF {
	struct edge {
		int from, to, rev;
		ll cap, cost, flow;
	};
	int N;
	vector<vector<edge>> ed;
	vi seen;
	vector<ll> dist, pi;
	vector<edge*> par;

	MCMF(int N) : N(N), ed(N), seen(N), dist(N), pi(N), par(N) {}

	void addEdge(int from, int to, ll cap, ll cost) {
		if (from == to) return;
		ed[from].push_back(edge{ from,to,sz(ed[to]),cap,cost,0 });
		ed[to].push_back(edge{ to,from,sz(ed[from]) - 1,0,-cost,0 });
	}

	void path(int s) {
		fill(all(seen), 0);
		fill(all(dist), INF);
		dist[s] = 0; ll di;

#if _LOCAL
		priority_queue<pair<ll, int>> q;
#else
		__gnu_pbds::priority_queue<pair<ll, int>> q;
		vector<decltype(q)::point_iterator> its(N);
#endif
		q.push({ 0, s });

		while (!q.empty()) {
			s = q.top().second; q.pop();
			seen[s] = 1; di = dist[s] + pi[s];
			for (edge& e : ed[s]) if (!seen[e.to]) {
				ll val = di - pi[e.to] + e.cost;
				if (e.cap - e.flow > 0 && val < dist[e.to]) {
					dist[e.to] = val;
					par[e.to] = &e;
#if _LOCAL
					q.push({ -dist[e.to],e.to });
#else
					if (its[e.to] == q.end())
						its[e.to] = q.push({ -dist[e.to], e.to });
					else
						q.modify(its[e.to], { -dist[e.to], e.to });
#endif
				}
			}
		}
		repp(i, 0, N) pi[i] = min(pi[i] + dist[i], INF);
	}

	pair<ll, ll> maxflow(int s, int t) {
		ll totflow = 0, totcost = 0;
		while (path(s), seen[t]) {
			ll fl = INF;
			for (edge* x = par[t]; x; x = par[x->from])
				fl = min(fl, x->cap - x->flow);

			totflow += fl;
			for (edge* x = par[t]; x; x = par[x->from]) {
				x->flow += fl;
				ed[x->to][x->rev].flow -= fl;
			}
		}
		repp(i, 0, N) for (edge& e : ed[i]) totcost += e.cost * e.flow;
		return { totflow, totcost / 2 };
	}

	// If some costs can be negative, call this before maxflow:
	void setpi(int s) { // (otherwise, leave this out)
		fill(all(pi), INF); pi[s] = 0;
		int it = N, ch = 1; ll v;
		while (ch-- && it--)
			repp(i, 0, N) if (pi[i] != INF)
			for (edge& e : ed[i]) if (e.cap)
				if ((v = pi[i] + e.cost) < pi[e.to])
					pi[e.to] = v, ch = 1;
		assert(it >= 0); // negative cost cycle
	}
};

void topsort(int u, vi& vis, vi& order, vector<vector<p2>>& edges)
{
	if (vis[u]) return;
	vis[u] = 1;

	repe(e, edges[u]) topsort(e.first, vis, order, edges);

	order.push_back(u);
}

signed main()
{
	fast();

	int n, k;
	cin >> n >> k;
	vi nums(n);
	rep(i, n) cin >> nums[i];
	int nodecnt = 2 * n + 3;
	MCMF flow(nodecnt);

	vector<vector<p2>> edges(nodecnt);
	auto add = [&](int a, int b, int cap, int cost)
	{
		flow.addEdge(a, b, cap, cost);
		edges[a].emplace_back(b, cost);
	};

	add(nodecnt - 3, nodecnt - 2, 4, 0);
	rep(i, n)
	{
		add(nodecnt - 2, 2 * i, 1, 0);
		add(2 * i+1, nodecnt-1, 1, 0);
		add(i * 2, 2 * i + 1, 1, -1);
		repp(j, i + 1, n)
		{
			if (nums[j]>=nums[i]+k)
			{
				add(2 * i + 1, 2 * j, 1, 0);
			}
		}
	}
	vi vis(nodecnt);
	vi order;
	rep(i, nodecnt)
	{
		topsort(i, vis, order, edges);
	}
	reverse(all(order));
	vi dp(nodecnt, inf);
	dp[nodecnt - 3] = 0;
	assert(order[0] == nodecnt-3);
	repe(u, order)
	{
		repe(e, edges[u])
		{
			dp[e.first] = min(dp[e.first], e.second + dp[u]);
		}
	}
	flow.pi = dp;
	cout << -flow.maxflow(nodecnt - 3, nodecnt - 1).second << "\n";
	

	return 0;
}