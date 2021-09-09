#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> dp(x + 1); // number of way make sum i
    dp[0] = 1;
    for(int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        for(int j = x; j >= 0; --j) {
            if(j >= a) {
                
                dp[j] += dp[j-a];
            }
        }
    }
    //for(int i = 0; i <= x; ++i)
		//cout << dp[i] << " ";
    cout << dp[x];
}
