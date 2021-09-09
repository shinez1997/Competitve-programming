#include <bits/stdc++.h>

using namespace std;
int mod = 1e9 + 7;
int n, x;
vector<int> coin;
vector<int> ans;

int main() {
    cin >> n >> x;
    coin.resize(n);
    ans.resize(x + 1, 1e9);
    for(int &i : coin) {
        cin >> i;
    }
    ans[0] = 0;
    for(int i = 1; i <= x + 1; ++i) {
        for(int j : coin) {
            if(i - j >= 0) {
                ans[i] = min(ans[i], ans[i - j] + 1);
            }
        }
    }
    if(ans[x] == 1e9)
        ans[x] = -1;

    cout <<ans[x];
    return 0;
}
