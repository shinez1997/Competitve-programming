#include <bits/stdc++.h>
using namespace std;
long long n, W;

int main() {    
    cin >> n >> W;
    
    vector<int> w(n), v(n);
    long long total_sum = 0;
    for(long long i = 0; i < n; ++i) {
        cin >> w[i] >> v[i];
        total_sum += v[i];
    }
    vector<long long> dp(total_sum + 1, 1e9 + 5); // dp[i] - minimum weight to get value i
    dp[0] = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = total_sum - v[i]; j >= 0; --j) {
            dp[j + v[i]] = min(dp[j + v[i]], dp[j] + w[i]);
        }
    }
    for(int i = total_sum; i >= 0; --i) {
        if(dp[i] <= W) {
            cout << i;
            break;
        }
    }
    return 0;

}