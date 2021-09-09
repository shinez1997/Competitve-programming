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
	int n;
	cin >> s >> n;
	vector<vector<int>> f(26, vector<int>(26, 1e9 + 5));  //minimum number of way to move from i -> j
	vector<vector<int>> adj(26);
	for(int i = 0; i < n; ++i) {
		string t;
		cin >> t;
		int u = t[0] - 'A';
		int v = t[1] - 'A';
		adj[u].push_back(v);
	}
	for(int i = 0; i < 26; ++i) {
		priority_queue<pii> pq;
		pq.push({0, i});
		f[i][i] = 0;
		while(!pq.empty()) {
			int u = pq.top().S;
			int du = pq.top().F;
			pq.pop();
			//if(du != f[i][u]) continue;
			for(int x : adj[u]) {
				if(f[i][x] > -du + 1) {
					f[i][x] = -du + 1;
					pq.push({-f[i][x], x});
				}
			}
		}
	}
	//for(int i = 0; i < 26; ++i) {
		//for(int j = 0; j < 26; ++j) {
			//cout << f[i][j] << " ";
		//}
		//cout << endl;
	//}

	n = s.length();
	int ans = 1e9;
	for(int i = 0; i < 26; ++i) {
		int cnt = 0;
		bool ok = true;
		for(int j = 0; j < n; ++j) {
			int u = s[j] - 'A';
			if(f[u][i] > 1e8)
			{
				ok = false;
				break;
			}
			cnt += f[u][i];
		}
		if(ok)
			ans = min(ans, cnt);
	}
	if(ans > 1e7) {
		cout << "-1\n";
	}
	else {
		cout << ans << endl;
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
