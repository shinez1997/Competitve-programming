#include <bits/stdc++.h>

using namespace std;
bool checkValid(vector<int> arr, int k, int m) {
	int prev = arr[0];
	int cnt = 1;
	for(int i = 1; i < arr.size(); ++i) {
		if(arr[i] >= (prev + k) {
			++cnt;
			prev = arr[i];
		}
		
	}
	return cnt >= m;
}
	
void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	for(int &i : arr)	cin >> i;
	sort(arr.begin(), arr.end());
	int high = 1e9;
	int low = 0;
	int mid;
	int ans = 0;
	while(high >= low) {
		mid = low + (high - low) / 2;
		if(checkValid(arr, mid, m)) {
			ans = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	cout << ans << endl;

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)	solve();
	return 0;
}
