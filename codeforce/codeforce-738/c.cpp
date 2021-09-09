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
void dfs(int u, const vector<vector<int>>& adj, vector<int>& v, vector<int>& order) {
	if(v[u])
		return;
	v[u] = 1;
	for(int next : adj[u])
		dfs(next, adj, v, order);
	v[u] = 2;
	order.push_back(u);
}
void test_case() {
	int n;
	cin >> n;
	vector<vector<int>> adj(n + 2, vector<int>());
	for(int i = 1; i < n; ++i) {
		adj[i].push_back(i+1); // (n-1) edge i -> (i+1)
	}
	for(int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		if(x)
			adj[n+1].push_back(i);
		else
			adj[i].push_back(n+1);
	}
	vector<int> v(n+2, 0);
	vector<int> order;
	for(int i = 1; i <= n + 1; ++i) {
		if(!v[i])
			dfs(i, adj, v, order);
	}
    reverse(order.begin(), order.end());
    for(int i : order)
		cout << i << " ";
	cout << endl;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
    cin >> t;
    while(t--) test_case();
	return 0;
}
