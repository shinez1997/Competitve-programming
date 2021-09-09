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

void test_case() {
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	vector<vector<int>> dp(1 << n, vector<int>(n, 1e9)); // dp[s][i]: min cost to travel subset s end at city i
	for(int i = 0; i < n; ++i) 
		for(int j = 0; j < n; ++j) 
			cin >> a[i][j];
	for(int i = 0; i < n; ++i)
		dp[1 << i][i] = 0; // init cost in city is 0
	
	for(int s = 1; s < (1 << n); ++s) {
		for(int x = 0; x < n; ++x) {
			if((s & (1 << x)) == 0) { // city x not in s
				for(int  y = 0; y < n; ++y) { //from city y in s to x
					if(s & (1 << y)) {
						dp[s | (1 << x)][x] = min(dp[s | (1 << x)][x], dp[s][y] + a[y][x]);
					}
				}
			}
		}
	}
	//}
	//Debug(dp);
	int ans = 1e9;
	for(int i = 0; i < n; ++i)
		ans = min(ans, dp[(1<<n)-1][i]);
    cout << ans;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	test_case();
	return 0;
}
