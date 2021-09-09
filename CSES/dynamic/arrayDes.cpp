#include <bits/stdc++.h>
using namespace std;

int main() {
    int mod = 1e9 + 7;
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for(int &i : arr)   cin >> i;
    vector<vector<int>> dp(n, vector<int>(m + 1));
    if(arr[0] == 0)
        for(int i = 1; i <= m; ++i)
            dp[0][i] = 1;
    else
        dp[0][arr[0]] = 1;
    for(int i = 1; i < n; ++i) {
        if(arr[i] == 0) {
            for(int j = 1; j <= m; ++j) {
                for(int k : {j - 1, j, j + 1}) {
                    if(k > 0 && k <= m)
                        (dp[i][j] += dp[i - 1][k]) %= mod;
                }
            }
        }
        else {
            for(int k : {arr[i] - 1, arr[i], arr[i] + 1}) {
                if(k > 0 && k <= m)
                    (dp[i][arr[i]] += dp[i - 1][k]) %= mod;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= m; ++i) {
        (ans += dp[n - 1][i]) %= mod;
    }
    cout << ans;
    return 0;
}