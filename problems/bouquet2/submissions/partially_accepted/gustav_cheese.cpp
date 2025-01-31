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

struct flower{
    ll x, y;

    bool operator<(const flower& other) const {
        return false;
    }
};

double dist(ll x1, ll y1, ll x2, ll y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;
    vector<pair<double, flower>> r, g, b;
    for(int i = 0; i < n; i++){
        ll x, y;
        char c;
        cin >> x >> y >> c;
        double d = dist(0,0,x,y);
        if(c == 'R') r.push_back({d, {x, y}});
        if(c == 'G') g.push_back({d, {x, y}});
        if(c == 'B') b.push_back({d, {x, y}});
    }
    sort(all(r));
    sort(all(g));
    sort(all(b));
    while(sz(r) > 800) r.pop_back();
    while(sz(g) > 800) g.pop_back();
    while(sz(b) > 800) b.pop_back();
    double ans = linf;
    for(auto [d01, f1] : r){
        for(auto [d02, f2] : g){
            double d12 = dist(f1.x,f1.y,f2.x,f2.y);
            for(auto [d03,f3] : b){
                ans = min(ans, d01 + d12 + dist(f2.x,f2.y,f3.x,f3.y) + d03);
                ans = min(ans, d01 + dist(f1.x,f1.y,f3.x,f3.y) + dist(f3.x,f3.y,f2.x,f2.y) + d02);
                ans = min(ans, d02 + d12 + dist(f1.x,f1.y,f3.x,f3.y) + d03);
            }
        }
    }
    cout << fixed << setprecision(15) << ans << "\n";
}
