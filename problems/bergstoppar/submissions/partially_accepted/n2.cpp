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

    for(pi m:mountains){
        int x = get<0>(m);
        int y = get<1>(m);

        double r = y / (double)x;
        bool can_see = true;

        for(pi other_m:mountains){
            if(m == other_m){
                continue;
            }

            int other_x = get<0>(other_m);
            if(other_x > x){
                continue;
            }

            int other_y = get<1>(other_m);
            double other_r = other_y / (double) other_x; 
            if(other_r >= r){
                can_see = false;
                break;
            }
        }

        if(can_see){
            count++;
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

    int score = in_sight(m_before) + in_sight(m_after);

    cout << score;
}