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
template<typename T> void dbg(vector<T> &v){cout << "["; for(T &i : v) cout << i << " "; cout << "]" << endl;};
template<typename T> void dbg(vector<vector<T>> &v){for(auto &i : v) dbg(i);};
#else
#define debug(...)
#define dbg(...)
#endif






int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> adj[n + 1];
	for(int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 1; i <= n; ++i) {
		sort(adj[i].begin(), adj[i].end());
	}
	vector<bool> visited(n + 1, 0);
	queue<int> q;
	vector<int> path;
	q.push(1);
	bool first = true;
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		path.push_back(cur);
		if(cur == 1) {
			if(!first)
				break;
			first = false;
		}
		if(visited[cur])
			continue;
		visited[cur] = true;
		for(int &next : adj[cur])
			if(!visited[next])
				q.push(next);
		
	}
	for(int p : path) 
		cout << p << " ";
	return 0;
}
