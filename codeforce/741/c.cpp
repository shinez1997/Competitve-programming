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
	int m = n / 2;
	if(n&1)
		m++;
	for(int i = 0; i <= n / 2; ++i) {
		string tmp = s.substr(i, m);
		if(i + m < n) {
			if(s[i + m] == '0') {
				cout << (i + 1) << " " << (i + m + 1) << " " << (i + 1) << " " << (i + m) << endl;
				return;
			}
			//int j = m;
			
		}
	}
    
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
