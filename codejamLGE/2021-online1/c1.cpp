#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'
map<int, int> valid;
bool checkValid(int sum) {
	if(valid[sum] != 0)
		return valid[sum] == 1 ? true : false;
	valid[sum] = -1;
	int cntNum = (int)log10(sum) - 3;
	int ten = 1;
	while(cntNum--) ten *= 10;
	if(sum % 10000 == 2021 && (sum / (ten) == 2020))
	{
		valid[sum] = 1;
		return true;
	}
	return false;
}
void solve() {
	int n;
	cin >> n;
    int ans = 0;
	vector<vector<int> > arr(10);
	map<int, int> sumArr;
	for(int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		int k = num % 10;
		if(k < 0) k += 10;
		arr[k].push_back(num);
		int j = (11 - k) % 10;
		if(arr[j].size() != 0) {
			for(int num1 : arr[j]) {
				int sum = num1 + num;
				if(sum >=202021)
				if(checkValid(sum)) ++ans;
			}
		}
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
