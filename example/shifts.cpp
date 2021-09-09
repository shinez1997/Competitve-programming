
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

/*
 Google kickstart round G-2019
*/
void test_case() {
	int n, h;
	cin >> n >> h;
	vector<int> a(n);
	vector<int> b(n);
	for(int& x : a) cin >> x;
	for(int& x : b) cin >> x;
    ll k = 1;
    ll ans = 0;
    for(int i = 0; i < n; ++i) k *= 3;
    for(ll i = k - 1; i >= 0; --i) {
		ll A = 0, B = 0; 
		ll tmp = i;
		for(int j = 0; j < n; ++j) {
			int shift = tmp % 3;
			if(shift == 0) {
				A += a[j];
			}
			else if(shift == 1)
				B += b[j];
			else {
				A += a[j];
				B += b[j];
			}
			tmp /= 3;
		}
		if(A >= h && B >= h)
			++ans;
	}
	cout << ans << endl;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for(int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		test_case();
	}
	return 0;
}
