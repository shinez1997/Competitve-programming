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
void test_case() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& x : a)
		cin >> x;
	sort(a.begin(), a.end());
	vector<ll> dp(a[n-1] + 1);
	//dp[i] number of way to get sort arr  with last number j;
	for(int i = 1; i <= a[0]; ++i)
		dp[i] = 1;
	for(int where = 1; where < n; ++where) {
		vector<ll> new_dp = dp;
		vector<ll> pref(a[where] + 1);
		for(int i = 1; i <= a[where]; ++i) {
			pref[i] = pref[i-1] + dp[i];
			pref[i] %= mod;
			new_dp[i] = pref[i];
		}
		dp = new_dp;
	}
	ll ans = 0;
	for(int i = 1; i <= a[n-1]; ++i) {
		ans += dp[i];
		ans %= mod;
	}
	ans *= n;
	ans %= mod;
	cout << ans << endl;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
    cin >> t;
    while(t--) test_case();
	return 0;
}
