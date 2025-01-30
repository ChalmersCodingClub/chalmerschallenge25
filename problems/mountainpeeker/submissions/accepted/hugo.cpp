#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll is_counter_clockwise(ll x[3], ll y[3]) {
    ll s = 0;
    for (int i = 0; i < 3; i++) {
        s += x[i] * y[(i+1)%3];
        s -= y[i] * x[(i+1)%3];
    }
    return s > 0;
}

int solve(vector<pair<ll,ll>>& m, ll h) {
    if (m.empty()) return 0;
    sort(m.begin(), m.end());

    ll x[3], y[3];
    x[0] = 0;
    y[0] = h;
    x[1] = m[0].first;
    y[1] = m[0].second;

    int cnt = 1;
    for (int i = 1; i < m.size(); i++) {
        x[2] = m[i].first;
        y[2] = m[i].second;
        if (is_counter_clockwise(x, y)) {
            cnt++;
            x[1] = m[i].first;
            y[1] = m[i].second;
        }
    }

    return cnt;
}

int main() {
    int n;
    ll h;
    vector<pair<ll, ll>> left, right;

    cin >> n >> h;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        if (x < 0) left.emplace_back(-x, y);
        else       right.emplace_back(x, y);
    }
    cout << solve(left, h) + solve(right, h) << "\n";
}
