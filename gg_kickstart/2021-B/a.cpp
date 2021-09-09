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
	string s;
	cin >> s;
	int cur = 1;
	cout << cur << " ";
	for(int i = 1; i <n; ++i) {
		if(s[i] > s[i-1]) {
			++cur;
		}
		else {
			cur = 1;
		}
		cout << cur << " ";
	}
	cout << endl;
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
