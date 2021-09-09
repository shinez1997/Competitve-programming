#include<bits/stdc++.h>
using namespace std;
int main() {
	string s, t;
	cin >> s >> t;
	int n = s.length();
	int m = t.length();
	//cout << n << m << endl;
	const int INF = 1e9 + 5;
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
	dp[0][0] = 0;
	for(int i = 0; i <= n; ++i) {
		for(int j = 0; j <= m; ++j) {
			if(i + j == 0)
				continue;
			dp[i][j] = min(dp[i][j], (i ? (dp[i-1][j] + 1) : INF));
			dp[i][j] = min(dp[i][j], (j ? (dp[i][j-1] + 1) : INF));
			dp[i][j] = min(dp[i][j], ((i && j) ? dp[i-1][j-1] + !(s[i] == t[j]):INF));
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}
