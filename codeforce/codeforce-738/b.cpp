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
	int n;
	cin >> n;
	string s;
	cin >> s;
	int start = 0;
	while(1) {
		if(s[start] != '?')
			break;
		++start;
	}
	for(int i = start + 1; i < n; ++i) {
		if(s[i] == '?')
			s[i] = (s[i-1] == 'R') ? 'B' : 'R';
	}
	for(int i = n - 1; i >= 0; --i) {
		if(s[i] == '?')
			s[i] = (s[i+1] == 'R') ? 'B' : 'R';
	}
    cout << s << endl;
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
