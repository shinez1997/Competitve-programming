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

//Warsaw template
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef _LOCAL_
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
const int mod = 998244353;
const int F = 0;
const int G = 1;
void rec(vi& a, vi& dp, int i, int n, int cur) {
	if(i == n) {
		dp[cur]++;
		dp[cur] %= mod;
		return;
	}
	rec(a, dp, i + 1, n, (cur + a[i]) % 10);
	rec(a, dp, i + 1, n, (cur * a[i]) % 10);
}

void test_case() {
	int n;
	cin >> n;
	vi a(n);
	for(int& x : a) cin >> x;
	vi dp(10);
	dp[a[0]] = 1;
	for(int i = 1; i < n; ++i) {
		vi new_dp(10);
		for(int way : {F,G}) {
			if(way == F) {
				//new_dp[(x + a[i])%10]++;
				//new_dp[(x + a[i])%10]%=mod;
				for(int j = 0; j < 10; ++j) {
					new_dp[(j + a[i])%10] += dp[j];
					new_dp[(j + a[i])%10] %= mod;
				}
			}
			else {
				//new_dp[(x * a[i])%10]++;
				//new_dp[(x * a[i])%10]%=mod;
				for(int j = 0; j < 10; ++j) {
					new_dp[(j*a[i])%10] += dp[j];
					new_dp[(j*a[i])%10] %= mod;
				}
			}
		}
		dp = new_dp;
	}
	for(int& i : dp)
		cout << i << endl;
    //rec(a, dp, 1, n, a[0]);
    //for(int& i : dp)
		//cout << i << endl;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	test_case();
	return 0;
}
