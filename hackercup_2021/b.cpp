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
	int n;
	cin >> n;
	vector<int> row(n);
	vector<int> col(n);
	vector<string> s(n);
	for(int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	for(int r = 0; r < n; ++r) {
		int cnt = 0;
		for(char c : s[r]) {
			if(c == '.')
				++cnt;
			else if(c == 'O') {
				cnt = -1;
				break;
			}
		}
		row[r] = cnt;
	}
	Debug(row);
	for(int i = 0; i < n; ++i) {
		int cnt = 0;
		for(int j = 0; j < n; ++j) {
			if(s[j][i] == '.')
				++cnt;
			else if(s[j][i] == 'O') {
				cnt = -1;
				break;
			}
		}
		col[i] = cnt;
	}
	Debug(col);
	int best = 1e9;
	int cnt = 0;
	for(int i = 0; i < n; ++i) {
		if(row[i] != -1) {
			if(row[i] < best) {
				best = row[i];
				cnt = 1;
			}
			else if(row[i] == best) {
				++cnt;
			}
		}
	}
	for(int i = 0; i < n; ++i) {
		if(col[i] != -1) {
			if(col[i] < best) {
				best = col[i];
				cnt = 1;
			}
			else if(col[i] == best) {
				++cnt;
			}
		}
	}
	if(best > 1e8) {
		cout << "Impossible\n";
	}
	else {
		cout << best << " " << cnt << endl;
	}
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
