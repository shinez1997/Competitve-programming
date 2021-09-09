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
void recur(int l, int r, vector<int> arr, int first, int last, int &ans, vector<vector<bool>>& visited) {
	if(first >= last)
		return;
	if(visited[first][last])
		return;
	visited[first][last] = 1;
	int sum = arr[first] + arr[last];
	if(sum >= l && sum <= r) {
		ans++;
		recur(l, r, arr, first + 1, last, ans, visited);
		recur(l, r, arr, first, last - 1, ans, visited);
	}
	else if(sum < l) {
		recur(l, r, arr, first + 1, last, ans, visited);
	}
	else {
		recur(l, r, arr, first, last - 1, ans, visited);
	}
}
void solve() {
	int n, l, r;
	cin >> n >> l >> r;
	int ans = 0;
	vector<int> arr(n);
	vector<vector<bool>> visited(n, vector<bool>(n));
	for(int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
    recur(l, r, arr, 0, n - 1, ans, visited);
    cout << ans << endl;
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
