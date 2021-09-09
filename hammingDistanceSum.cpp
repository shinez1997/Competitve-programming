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


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string a, b;
	cin >> a >> b;
	int n = a.length();
	int m = b.length();
	vector<int> pref1(m), pref0(m);
	pref1[0] = (b[0] == '1');
	pref0[0] = (b[0] == '0');
	for(int i = 1; i < m; ++i) {
		pref1[i] = pref1[i-1];
		if(b[i] == '1')
			pref1[i]++;
		pref0[i] = pref0[i-1];
		if(b[i] == '0')
			pref0[i]++;
	}
	int ans = 0;
	Debug(pref0);
	Debug(pref1);
	for(int i = 0; i < n; ++i) {
		int start = i - 1;
		int end = m - n + i;
		// _ _ _ _ 
		// _ _ _ _ _ _
		debug(i, start, end);
		if(a[i] == '0') {
			ans += pref1[end] - (start >= 0 ? pref1[start] : 0);
		}
		else {
			ans += pref0[end] - (start >= 0 ? pref0[start] : 0);
		}
		debug(ans);
		
	}
	cout << ans;
	return 0;
}
