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
const int mod = 2019;
void test_case() {
	string s;
	cin >> s;
	int n = s.length();
	int suf = 0;
	vector<int> cnt(mod);
	cnt[suf]++;
	ll ans = 0;
	int pot = 1;
	for(int i = n - 1; i >= 0; --i) {
		int d = s[i] - '0';
		suf = (suf + d * pot) % mod;
		ans += cnt[suf];
		pot = (pot * 10) % mod;
		cnt[suf]++;
	}
    cout << ans;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	test_case();
	return 0;
}
