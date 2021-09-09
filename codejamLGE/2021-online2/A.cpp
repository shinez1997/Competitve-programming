#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef pair<int, int> pii;
#define endl '\n'
#ifdef _LOCAL_
#define dbg(...) "[" << #__VA_ARGS__ ":" << (__VA_ARGS__) << "] "
template<typename T> void debug(vector<T> &v){for(T &i : v) cout << i << " ";cout << endl;};
template<typename T> void debug(T x){cout << dbg(x) << endl;};
template<typename T, typename ...Arg> 
    void debug(T t, Arg... arg) {cout << dbg(t); debug(arg...);};
#else
#define debug(...)
#endif
void solve() {
	vector<int> arr(10, 0);
	int n = 0;
	for(int i = 1; i <= 9; ++i) {
		int x;
		cin >> x;
		if(i == 6)
			arr[9] += x;
		else
			arr[i] += x;
		n += x;
	}
	vector<int> ans;
	int i = 1;
	int cnt = 0;
	while(i <= 9) {
		if(arr[i] == 0) {
			i++;
			continue;
		}
		if(cnt % 2 == n % 2)
			ans.push_back(i);
		else 
			ans.insert(ans.begin(), i);
		arr[i]--;
		cnt++;
	}
	for(int &x : ans) cout << x << " ";
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
