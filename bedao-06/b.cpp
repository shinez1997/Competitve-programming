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
	int m, n, k;
	cin >> m >> n >> k;
	vector<int> a(m);
	for(int& x : a) cin >> x;
	sort(a.rbegin(), a.rend());
	for(int i = 0; i + n - 1< m; ++i) {
		if(a[i] - a[i + n - 1] <= k) {
			ll sum = 0;
			for(int j = i; j <= i + n -1; ++j)
				sum += a[j];
			cout << sum;
			return;
		}
	}
	cout << "-2\n";
    
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	test_case();
	return 0;
}
