#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
map<char, int> m;
map<char, int> level;
string s1 = "QWERTYUIOP";
string s2 = "ASDFGHJKL";
string s3 = "ZXCVBNM";
int dis(char a, char b) {
	if(a == b) return 0;
	int ma = m[a];
	int mb = m[b];
	int la = level[a];
	int lb = level[b];
	if(la == lb) return abs(ma - mb);
	if(la > lb) {
		swap(la, lb);
		swap(ma, mb);
	}
	int add = 0;
	while(lb > la) {
		if(mb > ma) {
			++ma; 
		}
		++la;
		++add;
	}
	return abs(mb - ma) + add;
}
void solve() {
	string s;
	cin >> s;
	int n = s.length();
	int ans = n;
	for(int i = 1; i < n; ++i) {
		int prev = s[i - 1];
		int cur = s[i];
		ans += 2*dis(prev, cur);
	}
	cout << ans << endl;	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	int i = -1;
	for(auto c : s1) {
		m[c] = ++i;
		level[c] = 0;
	}
	i = 0;
	for(auto c : s2) {
		m[c] = ++i;
		level[c] = 1;
	}
	i = 1;
	for(auto c : s3) {
		m[c] = ++i;
		level[c] = 2;
	}
// 	for (auto& [key, value]: m) {
//         std::cout << key << " => " << value << endl;
// } 
	while(t--)	solve();
	return 0;
}
