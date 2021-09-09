#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef pair<int, int> pii;
#define endl '\n'
#define ll long long 
#define F first
#define S second
#ifdef _LOCAL_
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define debug(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#define Debug(x) cout << #x << ": ["; for(auto& i : x) cout << i << " "; cout << "]" << endl;
#else
#define debug(...)
#define Debug(...)
#endif
bool isVowel(char c) {
	return c == 'A' || c == 'E' || c == 'I' || c == 'U' || c == 'O';
}
void test_case() {
	string s;
	cin >> s;
	//int n = s.length();
	vector<int> cnt(26);
	vector<int> cntVow(2);
	for(char& c : s) {
		cnt[c - 'A']++;
		if(isVowel(c)) {
			cntVow[0]++;
		} else {
			cntVow[1]++;;
		}
	}
	int ans = 1e6;
	for(int i = 0; i < 26; ++i) {
		if(isVowel('A' + i)) {
			ans = min(ans, 2 * (cntVow[0] - cnt[i]) + cntVow[1]);
		}
		else {
			ans = min(ans, 2 * (cntVow[1] - cnt[i]) + cntVow[0]);
		}
	}
	cout << ans << endl; 
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		test_case();
	}
	return 0;
}
