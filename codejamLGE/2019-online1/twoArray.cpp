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
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for(int& x : a) cin >> x;
	for(int& x : b) cin >> x;
	sort(b.begin(), b.end());
	ll sum = 0;
	for(int& x : a) {
		auto i = lower_bound(b.begin(), b.end(), x);
		auto j = i;
		if(j != b.begin())
			j--;
		if(i == b.end())
			i--;
		sum += abs(*j - x) > abs(*i - x) ? *i :*j;
	}
    cout << sum << endl;
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
