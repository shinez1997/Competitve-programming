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
	ll a, b, c;
	cin >> a >> b >> c;
	string s;
	ll x = a;
	s = to_string(x);
	while(s.size() < c) {
	    c -= s.size();
		x += b;
		s = to_string(x);
	}
	cout << s[--c] << endl;
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
