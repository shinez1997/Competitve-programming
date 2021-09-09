#include <bits/stdc++.h>
#define rep(i, a, b)    for(int i = (a); i <= (b); ++i)
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for(int &i : h) cin >> i;
    vector<int> dp(n, 1e9);
    dp[0] = 0;
    dp[1] = abs(h[0] - h[1]);
    rep(i, 2, (n -1)) {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }
    cout << dp[n - 1];
    return 0;
}