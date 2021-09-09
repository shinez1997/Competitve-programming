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
void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	int max_index = max_element(arr.begin(), arr.end()) - arr.begin();
	int min_index = min_element(arr.begin(), arr.end()) - arr.begin();
	//cout << dbg(max_index) << dbg(min_index) << endl;
	int res;
	if(max_index > min_index) {
		res = min({n - min_index, max_index + 1, n - max_index + min_index + 1});
	}
	else {
		res = min({n - max_index, min_index + 1, n - min_index + max_index + 1});
	}
	cout << res << endl;
}


main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
    cin >> t;
    while(t--) solve();
	return 0;
}
