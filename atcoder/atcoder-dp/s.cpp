#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef pair<int, int> pii;
#define endl '\n'
#define ll long long 
#define F first
#define S second
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef _LOCAL_
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define debug(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#define Debug(x) cout << #x << ": ["; for(auto& i : x) cout << i << " "; cout << "]" << endl;
#else
#define debug(...)
#define Debug(...)
#endif
const int mod = 1e9 + 7;
void add(int &a, int b) {
	a += b;
	if(a >= mod)
		a -= mod;
}
void test_case() {
	string s;
	cin >> s;
	int d;
	cin >> d;
	int n = s.length();
	vector<vector<int>> dp(d, vector<int>(2));
	dp[0][0] = 1;
	for(int i = 0; i < n; ++i) {
		vector<vector<int>> new_dp(d, vector<int>(2));
		for(int sum = 0; sum < d; ++sum)
			for(int j : {0, 1}) { // 0 min not smaller already, 1 min smaller already
				for(int number = 0; number < 10; ++number) {
					if(number > int(s[i] - '0') && !j) {
						continue;
					}
					add(new_dp[(number+sum)%d][j || (number < s[i] - '0')],
						dp[sum][j]);
				}
			}
		dp = new_dp;
	}
	//for(int i = 0; i < d; ++i) {
		//cout << dp[i][0] << " ";
	//}
	int ans = 0;
	add(ans, dp[0][1]);
	add(ans, dp[0][0]);
	--ans;
	if(ans < 0)
		ans += mod;
	cout << ans;
    
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	test_case();
	return 0;
}
