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

auto Start = chrono::high_resolution_clock::now();
void resettimer() { Start = chrono::high_resolution_clock::now(); }
int elapsedmillis() { return chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - Start).count(); }

#if _LOCAL
#define assert(x) if (!(x)) __debugbreak()
#endif

int dp[31][31][31][31][31];

int best(int i, int a, int b, int c, int d, vi& nums)
{
	if (i == sz(nums)) return 0;
	int& v = dp[i][a][b][c][d];
	if (v != -1) return v;
	int ret = 0;

	if (nums[i] > nums[a]) ret = max(ret, 1 + best(i + 1, i, b, c, d, nums));
	if (nums[i] > nums[b]) ret = max(ret, 1 + best(i + 1, a, i, c, d, nums));
	if (nums[i] > nums[c]) ret = max(ret, 1 + best(i + 1, a, b, i, d, nums));
	if (nums[i] > nums[d]) ret = max(ret, 1 + best(i + 1, a, b, c, i, nums));
	ret = max(ret, best(i + 1, a, b, c, d, nums));

	return v = ret;
}

signed main()
{
	fast();

	memset(dp, -1, sizeof(dp));
	int n;
	cin >> n;
	vi nums(n);
	rep(i, n) cin >> nums[i];
	nums.insert(nums.begin(), -1);
	cout << best(1, 0, 0, 0, 0, nums) << endl;

	return 0;
}
