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
#define Debug(x) cout << #x << ": ["; for(auto& i : x) cout << i << " "; cout << "]" << endl;
#else
#define debug(...)
#define Debug(...)
#endif
void test_case() {

    
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int64_t n;
	cin >> n;
	//vector<int64_t> dp(n+1);
	//int64_t sum = 1;
	//const int mod = 1e9 + 7;
	//dp[1] = 1;
	//for(int64_t i = 2; i <= n; ++i) {
		//dp[i]++;
		//dp[i] +=i;
		//for(int j = 2*i; j <= n; j += i)
			//dp[j] += i;
		//sum += dp[i];
		//sum %= mod;
	//}
	//cout << sum;
	return 0;
}
