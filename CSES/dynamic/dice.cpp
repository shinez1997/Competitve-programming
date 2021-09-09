#include <bits/stdc++.h>

using namespace std;
int mod = 1e9 + 7;
int n;
vector<int> ans;
int solve(int k) {
    if(k < 0) return 0;
    if(ans[k]) return ans[k];
    int sum = 0;;
    for(int i = 1; i <=6; ++i) {
        sum += solve(k -i);
        sum %= mod;
    }
    ans[k] = sum;
    return sum;
}
int main() {
    
    cin >> n;
    ans.resize(n + 1);
    // for(int i : ans)
    //     cout << i << " ";
    ans[0] = 1;
    ans[1] = 1;
    cout << solve(n);
    return 0;
}