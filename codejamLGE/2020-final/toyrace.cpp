#include <bits/stdc++.h>

using namespace std;
int solve() {
    int n, x, y, k;
    cin >> n >> x >> y;
    double best = 1e9;
    for(int i = 0; i < n - 1; ++i) {
        cin >> k;
        best = min(best, (double)((double)x / (double)k));
    }
    //cout << "best" << best << endl;
    int my_speed;
    cin >> my_speed;
    if(best > (double)((double)x / (double)my_speed))
        return 0;
    int low = 1;
    int high = y;
    int mid;
    int my_best = 1e9;
    while(low < high) {
        mid = (low + high) / 2;
        double my_time = (double)((double)(x - mid) / (double)my_speed) + 1;
        //cout << my_time << " " << mid << endl;
        if(my_time >= best) {
            low = mid + 1;
        }
        else {
            high = mid;
            my_best = min(my_best, mid);
        }
    }
    if(my_best > 1e8)
        return -1;
    return my_best;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        
        cout << solve() << endl;
    }
}