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
#ifdef _LOCAL_
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define debug(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#define Debug(x) cout << #x << ": ["; for(auto& i : x) cout << i << " "; cout << "]" << endl;
#else
#define debug(...)
#define Debug(...)
#endif
int mod;
void add_self(int& a, int b) {
	a += b;
	if(a >= mod)
		a -= mod;
}
void test_case() {
	int n;
	cin >> n >> mod;
	vector<int64_t> dp(n + 1);
	dp[1] = 1;

    for(int i = 2; i <= n; ++i) {
		if(i == 2) {
			dp[2] = 2;
		}
		else {
			dp[i] += 2*dp[i-1];
			dp[i]++;
			dp[i] %= mod;
		}
		int tmp = dp[i] - dp[i-1] + mod;
		//if(tmp < 0)
			//tmp += mod;
		for(int j = 2*i; j <= n; j+=i)
			dp[j] += tmp;

	}
	cout << dp[n] << endl;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	test_case();
	return 0;
}
