#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <math.h>

using namespace std;

#define pi tuple<int, int>

int in_sight(vector<pi> mountains){
    long long max_r_y = -100000; //Anything >max_h, but -INFINITY causes overflow errors
    long long max_r_x = 1;
    int count = 0;

    for(int i = 0; i < mountains.size(); i++){
        pi m = mountains[i];
        long long x = get<0>(m);
        long long y = get<1>(m);

        if(y * max_r_x > max_r_y * x){ // same as angle > max_angle, but with integers
            count++;
            max_r_y = y;
            max_r_x = x;
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