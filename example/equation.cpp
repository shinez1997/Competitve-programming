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

/*
 Google kickstart G-2019
 n int a1->an
 find maximum k: (a1 xor k) + ... + (an xor k) <= m
 */
void test_case() {
	int n;
	ll m;
	cin >> n >> m;
    vector<ll> a(n);
    for(ll& x : a)	cin >> x;
    vector<int> cnt(55);
    ll sure = 0;
    for(int bit = 50; bit >= 0; --bit) {
		for(ll& x : a) {
			if((1LL << bit) & x)
				++cnt[bit];
		}
		sure += (1LL<<bit) * min(cnt[bit], n - cnt[bit]);
	}
	if(sure > m) {
		cout << "-1\n";
		return;
	}
	ll already = sure;
	ll best = 0;
	for(int bit = 50; bit >= 0; --bit) {
		ll cur = (1LL << bit) * min(cnt[bit], n - cnt[bit]);  //at bit i there are cnt bit 1
		ll maybe = already + (1LL << bit) * (n - cnt[bit]) - cur; //to set bit i of k as 1 -> add (n - cnt) to total
		if(maybe <= m) {
			already = maybe;
			best |= (1LL << bit);
		}
	}
	cout << best << endl;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
		cout << "Case #" << i << ": ";
		test_case();
	}
	return 0;
}
