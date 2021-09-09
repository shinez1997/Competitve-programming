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
vs a;
const int INF = 1e9 + 5;
int solve(string s, string t) {
	int n = s.length();
	int m = t.length();
	int i = 0, j = 0;
	int used = 0;
	while(i < n && j < m) {
		if(s[i] == t[j]) {
			used++;
			i++;
			j++;
		}
		else {
			j++;
		}
	}
	return n + m - 2 * used;
	
}
void test_case() {
	string s;
	cin >> s;
	int ans = INF;
	for(string t : a) {
		ans = min(ans, solve(s, t));
		//debug(s, t, ans, solve(s, t));
	}
	cout << ans << endl;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n = 1;
	while(n < 1e18) {
		a.push_back(to_string(n));
		n *= 2;
	}
	//solve("1504", "1024");
	int t;
    cin >> t;
    while(t--) test_case();
	return 0;
}
