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

vi manacher(const string& s) {
  int n = sz(s);
  vi p(n);
  for (int i=0,l=0,r=0; i < n; i++) {
    int t = r-i;
    if (i<r) p[i] = min(t, p[l+t]);
    int L = i-p[i], R = i+p[i];
    while (L>=1 && R+1<n && s[L-1] == s[R+1]) {
      p[i]++, L--, R++;
    }
    if (R>r) l=L, r=R;
  }
  return p;
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  int N, T; cin >> N >> T;
  string initial, target; cin >> initial >> target;
  assert(sz(initial) == N);
  assert(sz(target) == T);

  vi palindrome_width = manacher(initial);

  // Overfold on the L side onto the R side is not a problem since foldability of the R side implies
  // there exist a shorter valid fold on the L side to apply instead.

  vi dp_rcut_prefix_sum(N+1);
  vi dp_lcut_prefix_sum(N+1);
  rep(lcut, 0, N) {
    dp_lcut_prefix_sum[lcut+1] = dp_lcut_prefix_sum[lcut];
    if (lcut == 0 || dp_lcut_prefix_sum[lcut] > dp_lcut_prefix_sum[lcut-palindrome_width[lcut]]) {
      dp_lcut_prefix_sum[lcut+1]++;
    }
  }
  rep(rcut, 0, N) {
    dp_rcut_prefix_sum[rcut+1] = dp_rcut_prefix_sum[rcut];
    if (rcut == 0 || dp_rcut_prefix_sum[rcut] > dp_rcut_prefix_sum[rcut-palindrome_width[N-1-rcut]]) {
      dp_rcut_prefix_sum[rcut+1]++;
    }
  }

  rep(r, 0, 2) {
    for (int lcut : match(initial, target)) {
      int rcut = sz(initial) - sz(target) - lcut;
      if (dp_rcut_prefix_sum[rcut+1] > dp_rcut_prefix_sum[rcut] && dp_lcut_prefix_sum[lcut+1] > dp_lcut_prefix_sum[lcut]) {
        cout << "possible" << endl;
        return 0;
      }
    }
    reverse(all(target));
  }
  cout << "impossible" << endl;
}
