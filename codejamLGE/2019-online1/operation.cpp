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
#ifdef _LOCAL_
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define debug(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#define Debug(x) cout << #x << ": ["; for(int _=0; _<(int)x.size(); ++_) cout << x[_] << " "; cout << "]" << endl;
#else
#define debug(...)
#define Debug(...)
#endif
vector<ll> tree;
int n = 1e9;
int base = 1;
ll f(int x, int l, int r, int lx, int rx) {
	if(l <= lx && rx <= r)
		return tree[x];
	if(l > rx|| r < lx)
		return 0;
	int mid = (lx + rx) / 2;
	ll sum = 0;
	sum += f(2 *x, l, r, lx, mid);
	sum += f(2 * x + 1, l, r, mid + 1, rx);
	return sum;
}
void test_case() {
	while(base <= n)
		base *= 2;
	tree.resize(2 * base);
	int q;
	cin >> q;
	while(q--) {
		int opt;
		cin >> opt;
		if(opt == 1) {
			int i, v;
			cin >> i >> v;
			int x = base + i;
			tree[x] += v;
			for(int t = x / 2; t >= 1; t /= 2) {
				tree[t] = tree[2 * t] + tree[2 * t + 1];
			}
			cout << tree[1] << " ";
		}
		else if(opt == 2) {
			int l, r;
			cin >> l >> r;
			if(l > r)
				swap(l, r);
			cout << f(1, l, r, 0, base - 1) << " ";
		}
		else {
			int i;
			cin >> i;
			int x = base + i;
			tree[x] = 0;
			for(int t = x / 2; t >= 1; t /= 2) {
				tree[t] = tree[2 * t] + tree[2 * t + 1];
			}
			cout << tree[1] << " ";
		}
	}
    
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	test_case();
	return 0;
}
