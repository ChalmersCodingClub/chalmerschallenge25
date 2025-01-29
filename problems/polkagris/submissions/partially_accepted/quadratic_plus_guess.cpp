#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()

vi pi(const string& s) {
	vi p(sz(s));
	rep(i,1,sz(s)) {
		int g = p[i-1];
		while (g && s[i] != s[g]) g = p[g-1];
		p[i] = g + (s[i] == s[g]);
	}
	return p;
}

vi match(const string& s, const string& pat) {
	vi p = pi(pat + '\0' + s), res;
	rep(i,sz(p)-sz(s),sz(p))
		if (p[i] == sz(pat)) res.push_back(i - 2 * sz(pat));
	return res;
}

void fakesolve(string& initial, string& target) {
  int N = sz(initial);

  vi target_seen(26);
  for (char ch : target) {
    target_seen[ch - 'A'] = 1;
  }

  for (int l : match(initial, target)) {
    int r = l + sz(target) - 1;
    if (
           (l == 0 || (initial[l-1] == initial[l+1] && (l == 1 || initial[l-2] == initial[l] || initial[l-2] == initial[l+1])))
      && (r == N-1 || (initial[r-1] == initial[r+1] && (l == N-2 || initial[r+2] == initial[r] || initial[r+2] == initial[r+1])))
    ) {
      vi initial_seen(26);
      rep(i, l, r+1) {
        initial_seen[initial[i] - 'A'] = 1;
      }
      rep(i, 0, 26) {
        if (initial_seen[i] != target_seen[i]) goto next;
      }
      cout << "possible" << endl;
      return;
next: 1;
    }
  }
  cout << "impossible" << endl;
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  int N, T; cin >> N >> T;
  string initial, target; cin >> initial >> target;

  if (N > 10'000) {
    fakesolve(initial, target);
    return 0;
  }

  vi palindrome_width(N);
  rep(x, 0, N) {
    for (int i = 1; ; i++) {
      if (x+i < N && x-i >= 0 && initial[x+i] == initial[x-i]) {
        palindrome_width[x] = i;
      } else break;
    }
  }

  vector<vi> dp_suffix_sum(N, vi(N+1));
  vector<vi> dp_transpose_prefix_sum(N, vi(N+1));
  rep(l, 0, N) {
    for (int r = N-1; r >= l+sz(target)-1; r--) {
      // dp[l][r] = whether initial can be folded into initial[l,r] (inclusive)

      dp_suffix_sum[l][r] = dp_suffix_sum[l][r+1];
      dp_transpose_prefix_sum[r][l+1] = dp_transpose_prefix_sum[r][l];

      if ((l == 0 && r == N-1)
        || (dp_transpose_prefix_sum[r][l] > dp_transpose_prefix_sum[r][l-min(palindrome_width[l], r-l)])
        || (dp_suffix_sum[l][r] > dp_suffix_sum[l][r+min(palindrome_width[r], r-l)+1])
      ) {
        dp_suffix_sum[l][r]++;
        dp_transpose_prefix_sum[r][l+1]++;
      }
    }
  }

  rep(r, 0, 2) {
    for (int l : match(initial, target)) {
      int r = l + sz(target) - 1;
      if (dp_transpose_prefix_sum[r][l+1] > dp_transpose_prefix_sum[r][l]) {
        cout << "possible" << endl;
        return 0;
      }
    }
    reverse(all(target));
  }
  cout << "impossible" << endl;
}
