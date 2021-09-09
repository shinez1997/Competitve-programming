#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef pair<int, int> pii;
#define F first
#define S second
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
	vector<int> ans(n);
	vector<int> arr(n);
	vector<int> remains;
	unordered_map<int, vector<int>> pos;
	int cnt = 0;
	for(int i = 0; i < n; ++i) {
		cin >> arr[i];
		pos[arr[i]].push_back(i);
	}
	for(int i = 1; i <= n; ++i) {
		if((int)pos[i].size() >= k) {
			for(int j = 0; j < k; ++j) {
				ans[pos[i][j]] = j + 1;
			}
		}
		else if(!pos[i].empty()){
			remains.push_back(i);
			cnt += pos[i].size();
		}
	}
	int cur = 0;
	for(int i = 0; i < (int)remains.size(); ++i) {
		for(int x : pos[remains[i]]) {
			ans[x] = cur++ % k + 1;
			if(cur == (cnt / k) * k)
				break;
		}
	}
	
	for(int x : ans) {
		cout << x << " ";
	}
	cout << endl;
    
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
