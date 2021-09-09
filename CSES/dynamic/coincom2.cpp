#include <bits/stdc++.h>
using namespace std;

int main() {
    int mod = 1e9+7;
    int n, target;
    cin >> n >> target;
    vector<int> c(n);
    for (int&v : c) cin >> v;
        
    vector<vector<int>> dp(n + 1, vector<int>(target+1));
    dp[0][0] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= target; ++j) {
            dp[i][j] = dp[i - 1][j];
            int dif = j - c[i - 1];
            if(dif >= 0)
                dp[i][j] += dp[i][dif];
                dp[i][j] %= mod;
        }
    }
    cout << dp[n][target] << endl;
}