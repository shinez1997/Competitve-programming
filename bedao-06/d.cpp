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
	ll n, x;
	cin >> n >> x;
	vector<bool> isPrime(x + 100, 1);
	for(ll i = 2; i <= x; ++i) {
		if(!isPrime[i])
			continue;
		for(ll j = 2 * i; j <= x; j += i) {
			isPrime[j] = 0;
		}
	}
	isPrime[0] = 0;
	isPrime[1] = 0;
	vector<ll> a(n);
	vector<int> p;
	for(int i = 0; i < n; ++i) {
		cin>> a[i];
		if(a[i] > x)
			continue;
		if(a[i] <= x) {
			if(isPrime[a[i]]) {
				p.push_back(i);
			}
		}
	}
	Debug(p);
	int ans = 1e9;
	int N = p.size();

	for(int i = 0; i < N; ++i) {
		int cnt = 0;
		int cur = i;
		while(1) {
			if(cur >= N || p[cur] - p[i] + 1 > N) {
				break;
			}
			cnt++;
			cur++;
		}
		ans = min(ans, N - cnt);
	}
	
	if(ans == 1e9)
		cout << "0";
	else
		cout << ans;
	
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	test_case();
	//vector<int> a = {0, 3, 7};
	//int pos = lower_bound(a.begin(), a.end(), 2) - a.begin();
	//cout << pos;
	return 0;
}
