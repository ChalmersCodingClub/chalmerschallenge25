
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    
    map<int, int> p;
    for (int i = 0; i < n; i++) {
        string name;
        int pos;
        cin >> name >> pos;
        p[pos]++;
    }

    map<int, int> ivl;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (ivl.find(a) == ivl.end()) ivl[a] = b;
        ivl[a] = max(ivl[a], b);
    }

    int cnt = 0;
    auto b = ivl.begin();
    for (auto [pos, cups] : p) {
        while (b != ivl.end() && b->second < pos) b++;
        if (b == ivl.end() || b->first > pos) cnt += cups;
    }

    cout << cnt << "\n";
}
