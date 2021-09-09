#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef pair<int, int> pii;
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

struct segTree {
	int size;
	vector<ll> sums;
	void init(int n) {
		size = 1;
		while(size < n) size *= 2;
		sums.assign(2 * size, 0LL);
	}
	void build(vector<int>& arr, int x, int lx, int rx) {
		if(rx - lx == 1) {
			if(lx < (int)arr.size())
				sums[x] = arr[lx];
			return;
		}
		int m = (lx + rx) / 2;
		build(arr, 2 * x + 1, lx ,m);
		build(arr, 2 * x + 2, m, rx);
		sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
	}
	void build(vector<int>& arr) {
		build(arr, 0, 0, size);
	}
	void set(int i, int v, int x, int lx, int rx) {
		if(rx - lx == 1) {
			sums[x] = v;
			return;
		}
		int m = (lx + rx) / 2;
		if(i < m) {
			set(i, v, 2 * x + 1, lx, m);
		}
		else {
			set(i, v , 2 * x + 2, m, rx);
		}
		sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
	}
	void set(int i, int v) {
		set(i, v, 0, 0, size);
	}
	ll sum(int l , int r, int x, int lx, int rx) {
		if(l >= rx || lx >= r) {
			return 0;
		}
		if(lx >= l && rx <= r) {
			return sums[x];
		}
		int m = (lx + rx) / 2;
		ll s1 = sum(l, r, 2 * x + 1, lx, m);
		debug(s1);
		ll s2 = sum(l, r, 2 * x + 2, m, rx);
		debug(s2);
		return s1 + s2;
	}
	ll sum(int l, int r) {
		return sum(l, r, 0, 0, size);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	for(int &x : arr) {
		cin >> x;
	}
	dbg(arr);
	segTree st;
	st.init(n);
	st.build(arr);
	dbg(st.sums);
	while(m--) {
		int op;
		cin >> op;
		if(op == 1) {
			int i, v;
			cin >> i >> v;
			st.set(i, v);
		}
		else {
			int l, r;
			cin >> l >> r;
			cout << st.sum(l , r) << endl;
		}
	}
	return 0;
}
