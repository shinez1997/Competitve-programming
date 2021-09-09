#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef pair<int, int> pii;
#define F first
#define S second
#define endl '\n'
#define ll long long 
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
const int INF = 1e9 + 5;
struct segTree {
	int size;
	vector<pii> mins;
	void init(int n) {
		size = 1;
		while(size < n) size *= 2;
		mins.assign(2 * size, make_pair(INF, 1));
	}
	void set(int i, int v, int x, int lx, int rx) {
		if(rx - lx == 1) {
			mins[x] = make_pair(v, 1);
			return;
		}
		int m = (lx + rx) / 2;
		if(i < m)
			set(i, v, 2*x + 1, lx, m);
		else
			set(i, v, 2*x + 2, m, rx);
		pii m1 = mins[2*x+1];
		pii m2 = mins[2*x+2];
		if(m1.F < m2.F)
			mins[x] = mins[2*x+1];
		else if(m1.F > m2.F)
			mins[x] = mins[2*x+2];
		else
			mins[x] = make_pair(m1.F, m1.S + m2.S);
	}
	void build(vector<int>& a, int x, int lx, int rx) {
		if(rx - lx == 1) {
			if(lx < (int)a.size())
				mins[x] = make_pair(a[lx], 1);
			return;
		}
		int m = (lx + rx) / 2;
		build(a, 2*x+1, lx, m);
		build(a, 2*x+2, m, rx);
		pii m1 = mins[2*x+1];
		pii m2 = mins[2*x+2];
		if(m1.F < m2.F)
			mins[x] = mins[2*x+1];
		else if(m1.F > m2.F)
			mins[x] = mins[2*x+2];
		else
			mins[x] = make_pair(m1.F, m1.S + m2.S);	
	}
	pii getMin(int l, int r, int x, int lx, int rx) {
		if(lx >= r || rx <= l)
			return {INF, INF};
		if(lx >= l && rx <= r) 
			return mins[x];
		int m = (lx + rx) / 2;
		pii m1 = getMin(l, r, 2 * x + 1, lx, m);
		pii m2 = getMin(l, r, 2 * x + 2, m, rx);
		if(m1.F < m2.F)
			return m1;
		else if(m1.F > m2.F)
			return m2;
		else
			return make_pair(m1.F, m1.S + m2.S);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	segTree st;
	st.init(n);
	vector<int> a(n);
	for(int& x : a) cin >> x;
	st.build(a, 0, 0, st.size);
	while(m--) {
		int opt;
		cin >> opt;
		if(opt == 1) {
			int i, v;
			cin >> i >> v;
			st.set(i, v, 0, 0, st.size);
		}
		else {
			int l, r;
			cin >> l >> r;
			pii p = st.getMin(l, r, 0, 0, st.size);
			cout << p.F << " " << p.S << endl;
		}
	}
	return 0;
}
