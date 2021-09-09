#include <bits/stdc++.h>
using namespace std;
long long n, W;

int main() {    
    cin >> n >> W;
    vector<long long> dp(W + 1);

    for(long long i = 0; i < n; ++i) {
        long long weight, value;
        cin >> weight >> value;
        for(long long j = W - weight; j >= 0; --j) {
            dp[j + weight] = max(dp[j + weight], dp[j] + value);
        }
    }
    long long ans = 0;
    for(long long i : dp)
        ans = max(ans, i);
    cout << ans;
    return 0;

}