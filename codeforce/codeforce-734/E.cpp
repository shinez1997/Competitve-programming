#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef pair<int, int> pii;
#define endl '\n'
#ifdef _LOCAL_
#define dbg(...) "[" << #__VA_ARGS__ ":" << (__VA_ARGS__) << "] "
template<typename T> void debug(vector<T> &v){for(T &i : v) cout << i << " ";cout << endl;};
#else
#define debug(...)
#endif
void test_case() {
	int n, k;
	cin >> n >> k;
	vector<int> arr(n + 1);
	for(int i = 1; i <= n; ++i) cin >> arr[i];
	vector<vector<int>> dp(n + 1, vector<int>(n + 1)); //dp[i][j] max number of element equal index from 0..i have not delete j element
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j <= i; ++j) {
			//delete element i + 1 
			dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
			
			//not delete i + 1 -> arr[i+1] is index j + 1
			dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + ((arr[i + 1] == (j + 1)) ? 1 : 0));
		}
	}
	int ans = -1;
	for(int i = n; i >= 0; --i) {
		if(dp[n][i] >= k) {
			ans = n - i;
			break;
		}
	}
	cout << ans << endl;
	
    
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
