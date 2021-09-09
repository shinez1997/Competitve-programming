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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef _LOCAL_
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define debug(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#define Debug(x) cout << #x << ": ["; for(int _=0; _<(int)x.size(); ++_) cout << x[_] << " "; cout << "]" << endl;
#else
#define debug(...)
#define Debug(...)
#endif
bool isBlack(int x) {
	int a = ((x-1) / 8) % 2;
	int b = (x % 8) % 2;
	return a == b;
}
bool isBlack(string s) {
	int x = s[0] - 'A';
	return isBlack(8 * x + int(s[1] - '0')); 
}
void test_case() {
	string s;
	int x;
	cin >> s >> x;
	assert(x >= 1);
	assert(x <= 64);
	cout << (isBlack(x) == isBlack(s) ? "YES" : "NO") << endl; 
    
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//for(int i = 1; i <= 64; ++i) {
		//if(isBlack(i))
			//cout << i << " ";
	//}
	//cout << endl;
	//for(int i = 0; i < 8; ++i) {
		//for(int j = 1; j <= 8; ++j) {
			//string s = "AB";
			//s[0] = (char)('A' + i);
			//s[1] =  (char)('0' + j);
			//if(isBlack(s)) {
				//cout << s << " ";
			//}
		//}
	//}
	int t;
    cin >> t;
    while(t--) test_case();
	return 0;
}
