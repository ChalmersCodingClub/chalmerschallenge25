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

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  int N, T; cin >> N >> T;
  string initial, target; cin >> initial >> target;

  vi palindrome_width(N);
  rep(x, 0, N) {
    for (int i = 1; ; i++) {
      if (x+i < N && x-i >= 0 && initial[x+i] == initial[x-i]) {
        palindrome_width[x] = i;
      } else break;
    }
  }

  vector<vector<bool>> dp(N, vector<bool>(N));
  rep(l, 0, N) {
    for (int r = N-1; r >= l+sz(target)-1; r--) {
      // dp[l][r] = whether initial can be folded into initial[l,r] (inclusive)
      if (l == 0 && r == N-1) {
        dp[l][r] = true;
        goto next;
      }
      rep(i, 1, min(palindrome_width[l]+1, r-l+1)) {
        if (dp[l-i][r]) {
          dp[l][r] = true;
          goto next;
        }
      }
      rep(i, 1, min(palindrome_width[r]+1, r-l+1)) {
        if (dp[l][r+i]) {
          dp[l][r] = true;
          goto next;
        }
      }
next: 1;
    }
  }

  rep(r, 0, 2) {
    for (int l : match(initial, target)) {
      int r = l + sz(target) - 1;
      if (dp[l][r]) {
        cout << "possible" << endl;
        return 0;
      }
    }
    reverse(all(target));
  }
  cout << "impossible" << endl;
}
