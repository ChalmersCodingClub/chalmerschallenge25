#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <math.h>

using namespace std;

#define pi tuple<int, int>

int in_sight(vector<pi> mountains){
    double max_r = -INFINITY;
    int count = 0;

    for(int i = 0; i < mountains.size(); i++){
        pi m = mountains[i];
        int x = get<0>(m);
        int y = get<1>(m);

        double r = y / (double)x;
        if(r > max_r){
            count++;
            max_r = r;
        }
    }

    return count;
}

int main(){
    int n, h, x, y;
    cin >> n;
    cin >> h;

    vector<pi> m_before;
    vector<pi> m_after; 
    for(int i = 0; i < n; i++) {
        cin >> x;
        cin >> y;

        if(x < 0) {
            m_before.push_back(tuple(-x, y - h));
        } else {
            m_after.push_back(tuple(x, y - h));
        }
    }

    sort(m_before.begin(), m_before.end());
    sort(m_after.begin(), m_after.end());

    int score = in_sight(m_before) + in_sight(m_after);

    cout << score;
}