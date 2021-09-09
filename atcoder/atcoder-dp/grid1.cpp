#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
void add_self(int &a ,int b) {
    a += b;
    if(a > mod)
        a -= mod;
}
int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    const int r[2] = {0, 1};
    const int c[2] = {1, 0};
    for(string &x : s) cin >> x;
    vector<vector<int> > dp(h, vector<int>(w));
    dp[0][0] = 1;
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            for(int  k = 0; k < 2; ++k) {
                int col = j + c[k];
                int row = i + r[k];
                if(col < w && row < h && s[row][col] == '.') {
                    add_self(dp[row][col], dp[i][j]);
                }
            }
        }
    }
    cout << dp[h - 1][w - 1] << endl;
    return 0;
}