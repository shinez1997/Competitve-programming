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
const int MOD = 998244353;
void add(int& a, int b) {
	a += b;
	if(a >= MOD)
		a -= MOD;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> dp(m + 1); // dp[i] numbers of way used so far
	dp[0] = 1;
	for(int star = 0; star < n; ++star) {
		int L, R;
		cin >> L >> R;
		for(int used = m; used >= 0; --used) {
			for(int here = L + 1; here <= min(R, m - used); ++here) {
				add(dp[used+here], dp[used]);
			}
		}
	}
	int ans = 0;
	Debug(dp);
	for(int& x : dp) 
		ans += x;
	cout << ans;
	return 0;
}
