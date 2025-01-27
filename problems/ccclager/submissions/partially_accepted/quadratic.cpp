#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        string name;
        int pos;
        cin >> name >> pos;
        a.emplace_back(pos, 1);
        if (name == "Joshua" || name == "Gustav") a.back().second++;
    }

    vector<pair<int, int>> b;
    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        b.emplace_back(s, e);
    }

    int cnt = 0;
    for (auto [x, y] : a) {
        bool found = false;
        for (auto [s, e] : b) {
            found = found || (s <= x && x <= e);
        }
        if (!found) cnt += y;
    }

    cout << cnt << "\n";
}
