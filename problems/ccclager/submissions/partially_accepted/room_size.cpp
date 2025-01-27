#include <bits/stdc++.h>
using namespace std;

#define COVERED 100001
array<int, COVERED + 5> cups;
array<int, COVERED + 5> covered;
int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    cups.fill(0);
    covered.fill(0);
    
    for (int i = 0; i < n; i++) {
        string name;
        int pos;
        cin >> name >> pos;
        assert(pos < COVERED);
        cups[pos]++;
        if (name == "Joshua" || name == "Gustav") cups[pos]++;
    }

    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        assert(e < COVERED);
        covered[s] = max(e - s + 1, covered[s]);
    }

    int cnt = 0;
    for (int i = 0; i < COVERED; i++) {
        if (covered[i] > 0) {
            covered[i+1] = max(covered[i] - 1, covered[i+1]);
            covered[i] = 1;
        } else {
            cnt += cups[i];
        }
    }

    cout << cnt << "\n";
}
