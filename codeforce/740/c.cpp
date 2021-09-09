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
	vector<vector<int>> e(n, vector<int>(0));
	vector<pii> req(n); // require power before enter
	for(int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		req[i].S = i;
		for(int j = 0; j < t; ++j) {
			int x;
			cin >> x;
			e[i].push_back(x);
			req[i].F = max(req[i].F, x + 1 - j);
		}
	}
	sort(req.begin(), req.end());
	ll ans = req[0].F;
	ll cur = ans + e[req[0].S].size();
	for(int i = 1; i < n; ++i) {
		if(cur < req[i].F) {
			ans += req[i].F - cur;
			cur = req[i].F;
		}
		cur += e[req[i].S].size();
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
