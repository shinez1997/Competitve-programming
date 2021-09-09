#include <bits/stdc++.h>

using namespace std;
#define int long long 
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef pair<int, int> pii;
#define endl '\n'
#ifdef _LOCAL_
#define dbg(...) "[" << #__VA_ARGS__ ":" << (__VA_ARGS__) << "] "
template<typename T> void debug(vector<T> &v){for(T &i : v) cout << i << " ";cout << endl;};
template<typename T> void debug(T x){cout << dbg(x) << endl;};
template<typename T, typename ...Arg> 
    void debug(T t, Arg... arg) {cout << dbg(t); debug(arg...);};
#else
#define debug(...)
#endif
bool albert(char c) {
	for(char s : "ALBERT") {
		if(s == c)
			return 1;
	}
	return 0;
}
bool alice(char c) {
	for(char s : "ALICE") {
		if(s == c)
			return 1;
	}
	return 0;
}
void max_self(int& a, int b) {
	a = max(a, b);
}
void min_self(int& a, int b) {
	if(a < 0 && b < 0)
		a = max(a, b);
	else if(a > 0 && b > 0)
		a = min(a, b);
	else 
		a = max(a, b);
}
void solve() {
	string s;
	cin >> s;
	const int n = s.length();
	int dp[n][n][n];
	memset(dp, 0, sizeof dp);
	for(int S = 0; S < n; ++S) {
	for(int L = n - 1; L >= 0; L--) {
		for(int R = L; R < n; ++R) {
			if(L == R) {
				if(n % 2 == 1)
					dp[L][R][S] = 2 * albert(s[L]);
				else
					dp[L][R][S] = 1 * alice(s[L]);
			}
			else if(((R - L + 1) % 2) == (n % 2)) {
				if(albert(s[L])) {
					max_self(dp[L][R][S], 2 + dp[L + 1][R][S]);
				}
				else {
					max_self(dp[L][R][S], dp[L][R-1][S]);
				}
			}
			else {
				if(alice(s[R]))
					max_self(dp[L][R][S+1], 1 + dp[L][R-1][S]);
				else
					max_self(dp[L][R][S], dp[L][R-1][S]);
				if(alice(s[L]))
					max_self(dp[L][R][S+1], 1 + dp[L + 1][R][S]);
				else
					max_self(dp[L][R][S], dp[L + 1][R][S]);
			}
		}
		
	}
	}
	int ans = -1e9;
	for(int i = 0; i < n; ++i) {
		int diff = dp[0][n-1][i] - 2 * i;
		if(diff > 0 && abs(diff) < abs(ans))
			ans = diff;
	}
	if(ans > 0)
		cout << ans << endl;
	else
		cout << "-1" << endl;
}


main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
