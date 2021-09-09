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
struct DSU {
	vector<int> parent;
	vector<int> size;
	DSU(int n) {
		parent = vector<int>(n);
		iota(parent.begin(), parent.end(), 0);
		size = vector<int>(n, 1);
	}
	int get(int u) {
		return parent[u] = (u == parent[u]) ? u : get(parent[u]);
	}
	void joint(int u, int v) {
		u = get(u);
		v = get(v);
		if(u == v)
			return;
		if(size[u] < size[v])
			swap(u, v);
		parent[v] = u;
		size[u] += size[v];
		size[v] = 0;
	}
};
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, q;
	cin >> n >> q;
	DSU dsu(n);
	for(int i = 0; i < q; ++i) {
		int c, u, v;
		cin >> c >> u >> v;
		if(c) {
			if(dsu.get(u) == dsu.get(v))
				cout << "1\n";
			else 
				cout << "0\n";
		}
		else {
			dsu.joint(u, v);
		}
	}
	return 0;
}
