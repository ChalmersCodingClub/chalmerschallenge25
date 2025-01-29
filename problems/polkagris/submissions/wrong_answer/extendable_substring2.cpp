#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
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
  rep(i,sz(p)-sz(s),sz(p)) {
    if (p[i] == sz(pat)) res.push_back(i - 2 * sz(pat));
  }
  return res;
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  int N, T; cin >> N >> T;
  string initial, target; cin >> initial >> target;

  rep(r, 0, 2) {
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
        return 0;
  next: 1;
      }
    }
    reverse(all(target));
  }
  cout << "impossible" << endl;
}
