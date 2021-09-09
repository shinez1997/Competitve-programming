#include <bits/stdc++.h>
#define rep(i, a, b)    for(int i = (a); i <= (b); ++i)
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for(int &i : h) cin >> i;
    vector<int> dp(n, 1e9);
    dp[0] = 0;
    rep(i, 1, (n -1)) {
        rep(j, 1, k)
            if(i - j >= 0)
                dp[i] = min(dp[i - j] + abs(h[i] - h[i - j]), dp[i]);
    }
    cout << dp[n - 1];
    return 0;
}