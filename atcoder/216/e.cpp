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
	int n, k;
	cin >> n >> k;
    vector<int> a(n);
    for(int& x : a) cin >> x;
    sort(a.rbegin(), a.rend());
    a.push_back(0);
    Debug(a);
    int i = 0;
    ll ans = 0;
    int cur = a[0];
    while(1) {
		if(k <= 0 || cur == 0)
			break;
		while(a[i] == cur) {
			i++;
		}
		//int diff = cur - a[i];
		ans += min(k, i) * cur;
		debug(k , i, ans);
		cur--;
		k -= min(k, i);
	}
	cout << ans;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	test_case();
	return 0;
}
