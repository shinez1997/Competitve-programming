#include <bits/stdc++.h>

using namespace std;

int main() {
    int mod = 1e9 + 7;
    int n, x;
    cin >> n >> x;
    vector<int> price(n);
    vector<int> page(n);
    for(int &i : price) cin >> i;
    for(int &i : page) cin >> i;
    vector<vector<int>> dp(n + 1, vector<int>(x + 1));
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= x; ++j) {
            dp[i][j] = dp[i - 1][j];
            int left = j - price[i - 1];
            if(left >= 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][left] + page[i - 1]);
                dp[i][j] %= mod;
            }
        }
    }
    cout << dp[n][x];
    return 0;
}