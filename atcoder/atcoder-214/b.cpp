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
template<typename T> void dbg(vector<T> &v){cout << "["; for(T &i : v) cout << i << " "; cout << "]" << endl;};
template<typename T> void dbg(vector<vector<T>> &v){for(auto &i : v) dbg(i);};
#else
#define debug(...)
#define dbg(...)
#endif


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int s, t;
	cin >> s >> t;
	int ans = 0;
	for(int a = 0; a <= 100; ++a) {
		for(int b = 0; b <= 100; ++b) {
			for(int c = 0; c <= 100; ++c) {
				int sum = a + b + c;
				int p = a * b * c;
				if(sum <= s && p <= t)
					++ans;
			}
		}
	}
	cout << ans;
	return 0;
}
