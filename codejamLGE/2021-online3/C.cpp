#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef pair<int, int> pii;
#define endl '\n'
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef _LOCAL_
#define debug(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define debug(...)
#endif
#define F first
#define S second
const int MOD = 86400;
int add(int& a, int b) {
	a += b;
	while(a >= MOD)
		a-= MOD;
	while (a < 0)
		a += MOD;
	return a;
}
void valid(pii a, pii b, vector<int>& cnt) {
	if(a.F == b.F && a.S == b.S)
		return;
	vector<int> tmp;
	for(int& t : cnt) {
		if(add(a.F, t * a.S) == add(b.F, t * b.S))
			tmp.push_back(t);
	}
	cnt = tmp;
}
void solve() {
    int n;
    cin >> n;
    vector<pii> arr(n);
	vector<int> cnt(MOD);
	for(int i = 0; i < MOD; ++i) {
		cnt[i] = i;
	}
    for(int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		int h = (s[0] - '0') * 10 + s[1] - '0';
		int m = (s[3] - '0') * 10 + s[4] - '0';
		int sec = (s[6] - '0') * 10 + s[7] - '0';
		arr[i].F = 3600 * h + 60 * m + sec;
		//debug(arr[i].F, arr[i].S);
	}
	for(int i = 0; i < n; ++i) {
		cin >> arr[i].S;
		arr[i].S %= MOD;
	}	
	for(int i = 1; i < n; ++i) {
		if(cnt.empty())
			break;
		valid(arr[0], arr[i], cnt);
	}

	cout << cnt.size() << endl;
}


main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
    cin >> t;
    while(t--) solve();
	return 0;
}
