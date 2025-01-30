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


struct state
{
	int cost;
	p2 prev;
};

static constexpr state unit = state({ -inf,p2(-1,-1) });

struct Tree {
	typedef state T;
	T f(T a, T b)
	{
		if (a.cost > b.cost) return a;
		return b;
	}
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2 * n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};



signed main()
{
	fast();


	int n, k;
	cin >> n >> k;
	vi nums(n);
	rep(i, n) cin >> nums[i];
	rep(i, n) nums[i]--;

	vector<vector<state>> dp(2, vector<state>(n));



	vi disabled(n);
	vector<p2> backedges;
	int ans = 0;
	int mrel = 0;
	rep(_, 4)
	{
		rep(i, n) dp[0][i] = state({ 0, p2(i, 0) });
		rep(i, n) dp[1][i] = state({ 0, p2(i, 1) });

		bool any = 1;
		int rel = 0;
		while (any)
		{
			rel++;
			Tree top(n);
			any = 0;
			assert(1);
			rep(i, n)
			{
				state best = top.query(0, nums[i]-k+1);

				if (best.cost > dp[0][i].cost) dp[0][i] = best;


				if (!disabled[i] && dp[0][i].cost + 1 > dp[1][i].cost)
				{
					dp[1][i] = state({ dp[0][i].cost + 1, p2(i, 0) });
				}
				if (disabled[i] && dp[1][i].cost - 1 > dp[0][i].cost) dp[0][i] = state({ dp[1][i].cost - 1, p2(i, 1) });

				top.update(nums[i], state({ dp[1][i].cost, p2(i,1) }));

			}
			repe(b, backedges)
			{
				if (dp[1][b.second].cost < dp[0][b.first].cost)
				{
					dp[1][b.second] = state({ dp[0][b.first].cost, p2(b.first,0) });
					any = 1;
				}
			}
		}
		mrel = max(mrel, rel);

		int best = 0;
		rep(i, n)
		{
			if (dp[1][i].cost > dp[1][best].cost) best = i;
		}
		// found no augmenting path
		if (dp[1][best].cost < 0)
		{
			break;
		}
		ans += dp[1][best].cost;

		p2 pos = p2(best, 1);
		while (1)
		{
			p2 from = dp[pos.second][pos.first].prev;
			if (pos == from) break;
			p2 to = pos;
			if (from.first == to.first)
			{
				assert(from.second != to.second);
				if (from.second == 0)
				{
					disabled[from.first] = 1;
				}
				else disabled[from.first] = 0;
			}
			else
			{
				if (to.first > from.first)
				{
					backedges.emplace_back(to.first, from.first);
				}
				else backedges.erase(find(all(backedges), p2(from.first, to.first)));
			}
			sort(all(backedges), [](p2 a, p2 b)
				{
					return a.second > b.second;
				});
			if (pos == from) break;
			pos = from;
		}
	}
	cerr << mrel << "\n";
	cout << ans << "\n";



	return 0;
}