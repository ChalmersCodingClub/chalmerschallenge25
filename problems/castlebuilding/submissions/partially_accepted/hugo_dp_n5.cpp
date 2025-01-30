#include <bits/stdc++.h>

using namespace std;

array<int, 40> blocks;

int n, k;
char dp[40][40][40][40][40];
int best(int i=0, int a=0, int b=0, int c=0, int d=0) {
    if (i == n) return 0;
    if (dp[i][a][b][c][d] != -1) return dp[i][a][b][c][d];
    int consider = best(i+1, a, b, c, d);
    if (blocks[i] >= a) consider = max(consider, 1 + best(i+1, blocks[i]+k, b, c, d));
    if (blocks[i] >= b) consider = max(consider, 1 + best(i+1, a, blocks[i]+k, c, d));
    if (blocks[i] >= c) consider = max(consider, 1 + best(i+1, a, b, blocks[i]+k, d));
    if (blocks[i] >= d) consider = max(consider, 1 + best(i+1, a, b, c, blocks[i]+k));
    if (i < 40 && a < 40 && b < 40 && c < 40 && d < 40)
        dp[i][a][b][c][d] = consider;
    return consider;
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> n >> k;
    assert(n <= 30);
    for (int i = 0; i < n; i++) cin >> blocks[i];
    cout << best() << "\n";
    return 0;
}
