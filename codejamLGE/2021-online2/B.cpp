#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef pair<int, int> pii;
#define endl '\n'
#ifdef _LOCAL_
#define dbg(...) "[" << #__VA_ARGS__ ":" << (__VA_ARGS__) << "] "
template<typename T> void debug(vector<T> &v){for(T &i : v) cout << i << " ";cout << endl;};
template<typename T> void debug(T x){cout << dbg(x) << endl;};
template<typename T, typename ...Arg> 
    void debug(T t, Arg... arg) {cout << dbg(t); debug(arg...);};
#else
#define debug(...)
#endif
void solve() {
	int n, x;
	cin >> n >> x;
	set<int> s;
	map<int, int> m;
	for(int i = 0; i < n ; ++i) {
		int j;
		cin >> j;
		m[j]++;
		s.insert(j);
	}

	int cnt = 0;
	for(int j : s) {
		int ans = 0;
		for(int i = 0; i < 32; ++i) {
		    ans = x ^ j;
		}
		if(ans == j)
			cnt += m[ans] * (m[ans] - 1);
		else
			cnt += m[ans] * m[j];
	}
	cout << cnt / 2 << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
