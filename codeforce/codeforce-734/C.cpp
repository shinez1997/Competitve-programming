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
#else
#define debug(...)
#endif
void test_case() {
	int n;
	cin >> n;
	vector<vector<int>> cnt(5);
	for(int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		int l = s.length();
		vector<int> c(5);
		for(char ch : s) {
			c[ch - 'a']++;
		}
		for(int j = 0; j < 5; ++j) {
			cnt[j].push_back(2 * c[j] - l);
		}
	}
	for(int i = 0; i < 5; ++i) {
		sort(cnt[i].rbegin(), cnt[i].rend());
	}
	int ans = 0;
	for(int i = 0; i < 5; ++i) {
		int cur = 0;
		int j = 0;
		for(j = 0; j < (int)cnt[i].size(); ++j) {
			if(cur + cnt[i][j] <= 0)
				break;
			else {
				cur += cnt[i][j];
			}
		}
		ans = max(ans, j);
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
