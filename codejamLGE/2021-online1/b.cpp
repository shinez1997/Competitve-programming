#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve() {
	string s;
	cin >> s;
	int cnt0 = 0;
	int n = s.length();
	ll ans;
	if(n == 1)
	{
		cout << s;
		return;
	}
	vector<int> arr;
	for(char c : s) {
		if(c == '6')
			arr.push_back(9);
		else if(c == '0')
			++cnt0;
		else
			arr.push_back(c -'0');
	}
// 	for(int i : arr)
// 	    cout << i << " " ;
// 	cout << endl;
	long long s1 = 0;
	long long s2 = 0;
	sort(arr.begin(), arr.end(),[](int a, int b){return a > b;});
	if(arr.size() == 1 || arr.size() == 0) {
	    cout << '0' << endl;
	    return;
	}
	s1 = arr[0];
	s2 = arr[1];
	int i = 2;
	
	while(i < arr.size()) {
		if(i + 1 >= arr.size()) {
			ll p1 = (ll)((s1 * 10 + arr[i]) * s2);
			ll p2 = (ll)((s2 * 10 + arr[i]) * s1);
			if(p1 > p2) 
				s1 = s1 * 10 + arr[i++];
			else
				s2 = s2 * 10 + arr[i++];
		}
		else {
			ll p1 = (ll)((s1 * 10 + arr[i]) * (s2 * 10 + arr[i + 1]));
			ll p2 = (ll)((s2 * 10 + arr[i]) * (s1 * 10 + arr[i  +1]));
			if(p1 > p2) {
				s1 = s1 * 10 + arr[i];
				s2 = s2 * 10 + arr[i + 1];
				i += 2;
			}
			else {
				s2 = s2 * 10 + arr[i];
				s1 = s1 * 10 + arr[i + 1];
				i += 2;
			}
		}
			
	}
	
	ans = s1 * s2;
	while(cnt0--) ans *= 10;
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
