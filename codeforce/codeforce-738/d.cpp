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

struct DSU {
	vector<int> par;
	vector<int> size;
	DSU(int n) {
		par = vector<int>(n);
		iota(par.begin(), par.end(), 0);
		size = vector<int>(n, 1);
	}
	int find(int u) {
		return par[u] = ((u == par[u]) ? u : find(par[u]));
	}
	bool merge(int a, int b) {
		a = find(a);
		b = find(b);
		if(a == b)
			return false;
		if(size[a] < size[b])
			swap(a, b);
		par[b] = a;
		size[a] += size[b];
		size[b] = 0;
		return true;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	DSU a(n), b(n);
	int m1, m2;
	cin >> m1 >> m2;
	for(int i = 0; i < m1; ++i) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		a.merge(u, v);
	}
	for(int i = 0; i < m2; ++i) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		b.merge(u, v);
	}
	vector<int> lands;
	Debug(a.par);
	Debug(a.size);
	//swap(a, b);
	for(int i = 0; i < n; ++i) {
		if(a.size[i] > 0)
			lands.push_back(i);
	}
	Debug(lands);
	vector<pii> ans;
	for(int i = 0; i < (int)lands.size(); ++i) {
		for(int j = i + 1; j < (int) lands.size(); ++j) {
			if(b.merge(lands[i], lands[j]))
				ans.push_back({lands[i], lands[j]});
		}
	}
	cout << ans.size() << endl;
	for(pii& x : ans)
		cout << x.F + 1<< " " << x.S + 1<< endl;
	return 0;
}
