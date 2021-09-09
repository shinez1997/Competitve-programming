#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef pair<int, int> pii;
#define endl '\n'
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef _LOCAL_
#define debug(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define debug(...)
#endif
void test_case() {
	int n;
	cin >> n;
	if(n % 3 == 0) {
		cout << n / 3 << " " << n / 3 << endl;
	}
	else if(n % 3 == 1) {
		cout << n / 3 + 1 << " " << n / 3 << endl;
	}
	else {
		cout << n / 3 << " " << n / 3 + 1 << endl;
	}
    
}


main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
    cin >> t;
    while(t--) test_case();
	return 0;
}
