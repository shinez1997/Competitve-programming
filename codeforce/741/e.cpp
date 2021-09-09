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
void test_case() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<string> a;
	for(int i = 0; i < n; ++i) {
		for(int j = i; j < n; ++j) {
			a.push_back(s.substr(i, j - i + 1));
		}
	}
	//Debug(a);
    vector<int> order(a.size());
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
		return a[i] < a[j];
	});
	//Debug(order);
	vector<int> b(a.size());
	string cur = a[order[0]];
	b[order[0]] = 0;
	n = 0;
	for(int i = 1; i < (int)a.size(); ++i) {
		if(a[order[i]] != cur) {
			cur = a[order[i]];
			b[order[i]] = b[order[i-1]]+1;
			n = max(n, b[order[i]]);
		}
		else
			b[order[i]] = b[order[i-1]];
	}
	Debug(b);
	debug(n);
	int base = 1;
	int ans = 0;
	while(base <= n)
		base *= 2;
	vector<int> dp(b.size());
	vector<int> tree(2 * base);
	for(int i = 0; i < (int) b.size(); ++i) {
		int x = b[i] + base;
		int best = 0;
		while(x > 1) {
			if(x % 2 == 1) {
				best = max(best, tree[x-1]);
			}
			x/=2;
		}
		dp[i] = max(dp[i], best + 1);
		for(int j = b[i] + base; j >= 1; j /= 2) {
			tree[j] = max(tree[j], dp[i]);
		}
		ans = max(ans, dp[i]);
	}
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
