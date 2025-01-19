#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
const int inf = 0x3f3f3f3f;
const ll linf = 1234567890123456789;
const ll mod = 1000000007;
#define all(x) x.begin(), x.end()
#define debug(x) cerr << (#x) << " = " << (x) << endl
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for(int i = a; i < (b); ++i)

int k;
vvi dist;
vvi adj;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    cin >> k;
    dist = vvi(k, vi(k));
    adj = vvi(k);
    vpi order;
    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++) cin >> dist[i][j];
        order.emplace_back(dist[i][0], i);
    }
    sort(all(order));
    int p = k;
    vvi tw(k);
    for(int _i = 1; _i < k; _i++){
        int i = order[_i].second;
        int c = 0;
        int d0 = dist[0][i];
        int cd = 0;
        for(int _j = 1; _j < _i; _j++){
            int j = order[_j].second;
            if(c == tw[j][0]){
                int ncd = cd + ((d0-dist[i][j]) - (cd-sz(tw[j])+1))/2;
                c = tw[j][((d0-dist[i][j]) - (cd-sz(tw[j])+1))/2];
                cd = ncd;
            }
        }
        tw[i].push_back(c);
        while(cd < d0){
            int toadd = cd==d0-1 ? i : p++;
            adj[c].push_back(toadd);
            tw[i].push_back(toadd);
            c = toadd;
            adj.push_back(vi{});
            cd++;
        }
    }
    cout << p << endl;
    for(int i = 0; i < p; i++){
        for(int j : adj[i]){
            cout << i+1 << " " << j+1 << "\n";
        }
    }
}