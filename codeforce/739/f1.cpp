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
void test_case() {
	string s;
	int k;
	string ans = "";
	cin >> s >> k;
	int n = s.length();
	if(k == 1) {
		bool ok = true;
		for(int i = 1; i < n; ++i)
			if(s[i] > s[0])
				ok = false;
		if(ok) {
			for(int i = 0; i < n; ++i) 
				ans += s[0];
			}
		else {
			for(int i = 0; i < n; ++i) 
				ans += s[0] + 1;
		}
	}
	else {
		int fd = -1;
		int maxNum = -1;
		for(int i = 1; i < n; ++i) {
			if(s[i] != s[0]) {
				fd = i;
				break;
			}
		}
		char c = s[fd];
		for(int i = 0; i < n; ++i) {
			maxNum = max(maxNum, s[i] - '0');
		}
		if(maxNum == (s[0] - '0')) {
			for(int i = 0; i < fd; ++i)
				ans += s[0];
			for(int i = fd; i < n; ++i) {
				if(s[i] <= c)
					ans += c;
				else
					ans += s[0];
			}
		}
		else if(maxNum == (c - '0')) {
			for(int i = 0; i < fd; ++i)
				ans += s[0];
				
			for(int i = fd; i < n; ++i) {
				if(s[i] <= s[0])
					ans += s[0];
				else
					ans += c;
			}
		}
		else {
			for(int i = 0; i < fd; ++i)
				ans += s[0];
			ans += s[fd] + 1;
			for(int i = fd + 1; i < n; ++i) {
					ans += s[0];
			}
		}
	}
    cout << ans << endl;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
    cin >> t;
    while(t--) test_case();
	return 0;
}
