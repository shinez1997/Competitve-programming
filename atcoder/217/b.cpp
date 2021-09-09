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
#define Debug(x) cout << #x << ": ["; for(auto& ele : x) cout << ele << " "; cout << "]" << endl;
#else
#define debug(...)
#define Debug(...)
#endif
void test_case() {
	vs s = {"ARC", "AGC", "AHC", "ABC"};
	vector<int> used(4);
	for(int i = 0; i < 3; ++i) {
		string t;
		cin >> t;
		for(int j = 0; j < 4; ++j) {
			if(s[j] == t)
				used[j] = 1;
		}
	}
	Debug(used);
	for(int i = 0; i < 4; ++i) {
		if(!used[i]) 
			cout << s[i];
	}
    
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	test_case();
	return 0;
}
