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
const int INF = 1e5;
//const int nax = 305;
void test_case() {
	int n, x, y;
	cin >> n >> x >> y;
 
	vector<vector<int>> dp(x + 1, vector<int>(y + 1, INF)); //dp[i][j] minimum box to get i takoyaki and j taiyaki 
	dp[0][0] = 0;
	
	for(int i = 0; i < n; ++i) {
		int f, s;
		cin >> f >> s;
		for(int j = x ; j >= 0; --j) {
			for(int k = y ; k >= 0; --k) {
				
					int j2 = min(j + f, x);
					int k2 = min(j + s, y);
					dp[j2][k2] = min(dp[j2][k2], dp[j][k] + 1);
				
			}
		}
	}
	int ans = dp[x][y];
	if(ans > n)
		ans = -1;
	cout << ans << endl;;
}
 
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	test_case();
	return 0;
}
