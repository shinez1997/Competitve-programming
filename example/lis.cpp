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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n);
	
	for(int& x : a)	cin >> x;
	vector<int> order(n);
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&](int i, int j) {
		return a[i] < a[j];
	});
	Debug(order);
	int cur = a[order[0]];
	a[order[0]] = 0;
	for(int i = 1; i < n; ++i) {
		if(a[order[i]] != cur) {
			cur = a[order[i]];
			a[order[i]] = a[order[i-1]]+1;
		}
		else {
			a[order[i]] = a[order[i-1]];
		}
	}
	Debug(a);
	int base = 1;
	while(base <= n)
		base *= 2;
	debug(base);
	vector<int> dp(n);
	int ans = 0;
	vector<int> tree(2*base);
	for(int i = 0; i < n; ++i) {
		int x = a[i] + base;
		int best = 0;
		while(x > 1) {
			if(x % 2 == 1) {
				best = max(best, tree[x-1]);
			}
			x /= 2;
		}
		dp[i] = best + 1;
		ans = max(ans, dp[i]);
		debug(best, ans);
		for(int j = a[i] + base; j >= 1; j /= 2) {
			tree[j] = max(tree[j], dp[i]);
		}
	}
	cout << ans << endl;
	return 0;
}
