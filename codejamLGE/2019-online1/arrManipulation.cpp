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
	int n, q;
	cin >> n >> q;
	vector<vector<int>> a(n, vector<int>(n));
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j)
			cin >> a[i][j];
	}
	vector<ll> rSum(n), cSum(n);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			rSum[i] += a[i][j];
		}
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cSum[i] += a[j][i];
		}
	}
    while(q--) {
		int r1, r2, c1, c2, v;
		cin >> r1 >> c1 >> r2 >> c2 >> v;
		r1--;
		c1--;
		r2--;
		c2--;
		for(int row = r1; row <= r2; ++row) {
			rSum[row] += (c2 - c1 + 1) * v;
		}
		for(int col = c1; col <= c2; ++col) {
			cSum[col] += (r2 - r1 +1) * v;
		}
	}
	for(int i = 0; i < n; ++i) 
		cout << rSum[i] << " ";
	cout << endl;
	for(int i = 0; i < n; ++i) 
		cout << cSum[i] << " ";
	cout << endl;
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
