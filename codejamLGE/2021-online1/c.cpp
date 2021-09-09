#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'
map<pair<ll, ll>, bool> valid;
bool checkValid(ll a, ll b) {
	if(valid.find(make_pair(a, b)) != valid.end()) 
		return valid[{a, b}];
	valid[{a, b}] = false;
	ll sum = a + b;
	if(sum <= 0)
		return false;
	string s = to_string(sum);
	if(s.length() < 4)
		return false;
	if(s.substr(0, 4) == "2020" && s.substr(s.length() - 4, 4) == "2021") {
		valid[{a,b}] = true;
		return true;
	}
	return false;
}
void solve() {
	int n;
	cin >> n;
	ll ans = 0;
	vector<vector<ll> > arr(10);
	map<ll , ll> myMap;
	for(int i = 0; i < n; ++i) {
		ll num;
		cin >> num;
		int k = num % 10;
		if(k < 0) k += 10;
		if(myMap[num])
			++myMap[num];
		else {
			arr[k].push_back(num);
			myMap[num] = 1;
		}
	}
	int i = 5, j =6;
	while(1) {
	    //cout << i << " " << j << endl;
		if(i == 0) break;
		if(j == 10) j = 0;
		if(arr[i].size() == 0 || arr[j].size() == 0) {
			--i, ++j;
			continue;
		}
		for(ll num1 : arr[i]) {
			for(ll num2 : arr[j]) {
			    bool check;
				if(num1 < num2)
				check = checkValid(num1, num2);
				else check = checkValid(num2, num1);
				if(check) 	ans += (ll) (myMap[num1] * myMap[num2]);
			}
		}
		--i, ++j;
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
