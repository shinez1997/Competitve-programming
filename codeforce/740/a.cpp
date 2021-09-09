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
	vector<int> a(n + 2);
	for(int i = 1; i <= n; ++i) cin >> a[i];
	int cnt = 1;
	a[n+1] = 1e9;
	while(1) {
		bool ok = true;
		if(cnt % 2) {
			for(int i = 1; i <= n; i ++) {
				if(i % 2)
					if(a[i] > a[i+1])
					{
						swap(a[i], a[i+1]);
						ok = false;
					}
				if(a[i] != i)
					ok = false;
			}
		}
		else {
			for(int  i = 1; i <= n; i ++) {
				if(i % 2 == 0)
					if(a[i] > a[i+1])
					{
						swap(a[i], a[i+1]);
						ok = false;
					}
				if(a[i] != i)
					ok = false;
			}
		}
		if(ok) break;
		cnt++;
	}
	cout << cnt - 1 << endl;
	
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
