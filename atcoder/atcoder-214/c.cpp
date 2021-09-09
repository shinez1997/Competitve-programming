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
template<typename T> void dbg(vector<T> &v){cout << ":["; for(T &i : v) cout << i << " "; cout << "]" << endl;};
template<typename T> void dbg(vector<vector<T>> &v){for(auto &i : v) dbg(i);};
#else
#define debug(...)
#define dbg(...)
#endif
void test_case() {

    
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	const int INF = 1e9 + 5;
	vector<int> s(n), t(n);
	vector<int> ans(n, INF);
	for(int i = 0; i < n; ++i)
		cin >> s[i];
	for(int i = 0; i < n; ++i) {
		cin >> t[i];
		int time = t[i];
		for(int cnt = 0; cnt < n; ++cnt) {
			int nxt = (i + cnt) % n;
			if(time >= ans[nxt])
				break;
			ans[nxt] = min(time, ans[nxt]);
			time += s[nxt];
		}
	}
	for(int& x : ans) 
		cout << x << endl;
	return 0;
}
