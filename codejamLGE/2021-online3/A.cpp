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
void solve() {
	int n, k;
	int ans = 0;
	map<pair<string, int>, int> m;
	cin >> n >> k;
	for(int i = 0; i < n; ++i) {
		string s;
		int cnt = 0;
		cin >> s;
		for(char& c: s) {
			if(c >= 'a' && c < 'z') {
				++cnt;
			}
			else {
				c += 'a' - 'A';
			}
		}
		sort(s.begin(), s.end());
		auto p = make_pair(s, cnt);
		++m[p]; 
	}
	
	for(auto const& [key, val] : m) {
		//int value = iter->second;
	    //cout << key.first << endl;
		ans += val * (val - 1) / 2;
	}
	cout << ans << endl;
	
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
