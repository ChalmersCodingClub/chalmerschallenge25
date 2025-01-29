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
  assert(sz(initial) == N);
  assert(sz(target) == T);

  // Overfold on the L side onto the R side is not a problem since foldability of the R side implies
  // there exist a shorter valid fold on the L side to apply instead.

  vector<bool> dp_rcut(N);
  vector<bool> dp_lcut(N);
  dp_rcut[0] = true;
  dp_lcut[0] = true;
  rep(lcut, 0, N) {
    for (int i = 1; ; i++) {
      if (lcut-i<0 || lcut+i >= N || initial[lcut-i] != initial[lcut+i]) break;
      if (dp_lcut[lcut-i]) {
        dp_lcut[lcut] = true;
        break;
      }
    }
  }
  rep(rcut, 0, N) {
    for (int i = 1; ; i++) {
      int r = N-1-rcut;
      if (r-i<0 || r+i >= N || initial[r-i] != initial[r+i]) break;
      if (dp_rcut[rcut-i]) {
        dp_rcut[rcut] = true;
        break;
      }
    }
  }

  rep(r, 0, 2) {
    for (int lcut : match(initial, target)) {
      int rcut = sz(initial) - sz(target) - lcut;
      if (dp_rcut[rcut] && dp_lcut[lcut]) {
        cout << "possible" << endl;
        return 0;
      }
    }
    reverse(all(target));
  }
  cout << "impossible" << endl;
}
