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
#define Debug(x) cout << #x << ": ["; for(int _=0; _<(int)x.size(); ++_) cout << x[_] << " "; cout << "]" << endl;
#else
#define debug(...)
#define Debug(...)
#endif
const int mod = 1e9 + 7;
void add(ll &a, ll b) {
	a += b;
	if(a >= mod)
		a-= mod;
}

void test_case() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> can(n, vector<int>(n));
	while(m--) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		can[a][b]++;
	}
	vector<vector<ll>> dp(1<<n, vector<ll>(n)); // dp[s][i] number of way to fly to subset s with last city i
	dp[1][0] = 1;
	for(int s = 1; s < (1<<n); ++s) {
		if((s & 1) == 0)
			continue;
		for(int end = 1; end < n; ++end) {
			if(!(s & (1 << end))) // x not in s
				continue;
			int prev = s - (1 << end);
			for(int y = 1; y < n; ++y) { //y in s
				if(s & (1 << y)) {
					for(int i = 0; i < can[y][end]; ++i) {
						dp[s][end] += dp[prev][y];
						dp[s][end] %= mod;
					}
				}
			}
		}
	}

	cout << dp[(1<<n)-1][n-1];
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	test_case();
	return 0;
}
