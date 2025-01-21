
#include <bits/stdc++.h>
using namespace std;

string opts[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

int main() {
    int n;
    cin >> n;
    
    map<string, int> cnt;
    for (int i = 0; i < 13; i++) cnt[opts[i]] = 4;
    for (int i = 0; i < n; i++) {
        string l;
        cin >> l;
        l = l.substr(0, l.size() - 1);
        cnt[l]--;
    }
    int gg = 0;
    for (int i = 0; i < 13; i++) gg = max(cnt[opts[i]], gg);
    cout << fixed << setprecision(10) << ((double)gg / (52-n)) << "\n";
}
