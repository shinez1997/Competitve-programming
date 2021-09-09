#include <bits/stdc++.h>

using namespace std;

int main() {
    int mod = 1e9 + 7;
    int n;
    cin >> n;
    vector<string> path(n);
    for(string &i : path) {
        cin >> i;
    }
    vector<vector<int>> dp(n, vector<int>(n));
    dp[0][0] = 1;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(path[i][j] == '*') {
                dp[i][j] = 0;
            }
            else {
                if(j > 0)
                    (dp[i][j] += dp[i][j - 1]) %= mod;
                if(i > 0)
                    (dp[i][j] += dp[i - 1][j]) %= mod;

            }
            
        }
    }
    cout << dp[n - 1][n - 1];
    return 0;
}