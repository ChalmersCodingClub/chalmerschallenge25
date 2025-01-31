#pragma warning(disable : 4996)
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string.h>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <ctype.h>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <array>
#include <deque>
#include <bitset>
#include <immintrin.h>

using namespace std;


#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define nl "\n"
#define nf endl
#define ll long long
#define dl double long
#define uint unsigned int
#define pb push_back
#define _ << " " <<
#define mod 1'000'000'007
#define mp make_pair
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef multiset<ll> mll;
typedef pair<double, double> pdd;
typedef array<ll, 3> tripple;
ll INF = 1e15;
ll n, k, s, m, sum, c;

vector <pii> run(vector<pii> edges){
    ios::sync_with_stdio(0);
    cin.tie(0);  
    
    int maxdeg = 0;
    vector<int> deg(1000, 0);
    vector<pii> newE;
    set<pii> e;
    for (int i = 0; i < edges.size(); i++) {
        deg[edges[i].first]++;
        deg[edges[i].second]++;
        e.insert({ edges[i].first , edges[i].second });
        e.insert({ edges[i].second , edges[i].first });
        int tmp = max(deg[edges[i].first], deg[edges[i].second]);
        maxdeg = max(maxdeg, tmp);
    }
    if (maxdeg >= 30) return {};
    for (int i = 1, t = 0; i < 1000, t < 30; i++)
    {
        if (!e.contains({ 0,i })) {
            newE.push_back({ 0,i });
            t++;
        }
    }
    return newE;
}
