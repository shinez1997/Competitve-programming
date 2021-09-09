#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dp(3);
    for(int day = 0; day < n; ++day) {
        vector<int> c(3);
        for(int &i : c) {
            cin >> i;
        }
        vector<int> new_dp(3);
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                if(i != j) {
                    new_dp[i] = max(new_dp[i], dp[j] + c[i]);
                }
            }
        }
        dp =  new_dp;
    }
    cout << max({dp[0], dp[1], dp[2]});
    return 0;
}