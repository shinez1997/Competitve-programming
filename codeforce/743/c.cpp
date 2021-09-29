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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//Warsaw template
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef _LOCAL_
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

bool bfs(int u, int p, vector<vector<int>> adj, vector<int>& vis) {
	if(vis[u] == 2) {
		return true;
	}
	if(vis[u] == 1)
		return false;
	vis[u] = 1;
	for(int v : adj[u]) {
		if(v == p) 
			continue;
		if(bfs(v, u, adj, vis) == false) 
			return false;
	}
	vis[u] = 2;
	return true;
}
bool checkCycle(vector<vector<int>> adj, vector<int>& vis) {
	int n = adj.size();
	
	for(int i = 0; i < n; ++i) {
		if(vis[i])
			continue;
		if(bfs(i, -1, adj, vis) == false)
			return true;
	}
	return false;
}
void dfs(int u, int p, vector<vector<int>> adj, vector<int>& vis) {
	if(vis[u])
		return;
	if(adj[u].empty())
		vis[u] = 1;
	for(int v : adj[u]) {
		if(p == v)
			continue;
		dfs(v, u, adj, vis);
		if(v > u)
			vis[u] = max(vis[u], vis[v] + 1);
		else
			vis[u] = max(vis[u], vis[v]);
	}
}
void test_case() {
	int n;
	cin >> n;
	vector<vector<int>> adj(n);
	vector<int> vis(n);

	for(int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		while(k--) {
			int v;
			cin >> v;
			v--;
			adj[i].push_back(v);
		}
	}
	if(checkCycle(adj, vis)) {
		//debug() << imie(vis);
		cout << "-1\n";
		return;
	}
	vis.clear();
	vis.resize(n);
	for(int i = 0; i < n; ++i) {
		if(!vis[i])
			dfs(i, -1, adj, vis);
	}
	int ans = 0;
	for(int i = 0; i < n; ++i)
		ans = max(ans, vis[i]);
	//debug() << imie(vis);
	cout << ans << endl;
    
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
