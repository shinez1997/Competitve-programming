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
	string s;
	cin >> s;
	vector<int> cnt(26);
	for(char c : s) {
		cnt[c - 'a']++;
	}
	int ans = 0;
	int cnt1 = 0;
	for(int i = 0; i < 26; ++i) {
		if(cnt[i] > 1)
			++ans;
		else if(cnt[i] == 1)
			++cnt1;
	}
	ans += cnt1 / 2;
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
