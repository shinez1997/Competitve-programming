#include<bits/stdc++.h>
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
#ifdef _LOCAL_
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define debug(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#define Debug(x) cout << #x << ": ["; for(auto& ele : x) cout << ele << " "; cout << "]" << endl;
#else
#define debug(...)
#define Debug(...)
#endif
int main() {
	int n, q;
	cin >> n >> q;
	int base = 1;
	while(base < n) {
		base *= 2;
	}
	vector<int> tree(2 * base, 1e9);
	auto update = [&](int i, int v) {
		int x = i + base;
		tree[x] = v;
		x /= 2;
		while(x >= 1) {
			tree[x] = min(tree[2*x], tree[2*x + 1]);
			x /= 2;
		}
	};
	auto get = [&](int l, int r) {
		l += base;
		r += base - 1;
		int ans = min(tree[l], tree[r]);
		while(l + 1 < r) {
			ans = min(ans, tree[l + 1]);
			ans = min(ans, tree[r - 1]);
			l /= 2;
			r /= 2;
		}
		return ans;
	};
	for(int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		update(i, v);
	}
	//Debug(tree);
	while(q--) {
		int opt;
		cin >> opt;
		if(opt == 1) {
			int i, v;
			cin >> i >> v;
			update(i, v);
			Debug(tree);
		}
		else {
			int l, r;
			cin >> l >> r;
			cout << get(l, r) << endl;;
		}
	}
}
