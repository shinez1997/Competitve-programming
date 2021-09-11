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
int base = 1;
struct Querry {
	int type;
	string l, r;
	ll val;
	int left, right;
};
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
	
	int q;
	cin >> q;
	vector<Querry> v;
	while(q--) {
		Querry t;
		cin >> t.type;
		if(t.type == 1) {
			cin >> t.l >> t.val;
		}
		else if(t.type == 2) {
			cin >> t.l >> t.r;
		}
		else {
			cin >> t.l;
		}
		v.push_back(t);
	}
	vector<string> s;
	for(Querry t : v){
		s.push_back(t.l);
		if(t.r != "")
			s.push_back(t.r);
	}
	sort(s.begin(), s.end(), [&](string a, string b) {
		if(a.length() > b.length())
			return false;
		if(a.length() < b.length())
			return true;
		return a < b;
	});
	s.resize( unique(s.begin(), s.end()) - s.begin());
	//auto get = [&](string a) {
		//return lower_bound(s.begin(), s.end(), a) - s.begin();
	//};
	unordered_map<string, int> hash;
	for(int i = 0; i < (int)s.size(); ++i) 
		hash[s[i]] = i;
	int n = s.size();
	while(base <= n)
		base *= 2;
	tree.resize(2 * base);
	for(Querry qu : v) {
		qu.left = hash[qu.l];
		if(qu.r != " ")
			qu.right = hash[qu.r];
		if(qu.type == 1) {
			int x = base + qu.left;
			tree[x] += qu.val;
			for(int t = x / 2; t >= 1; t /= 2) {
				tree[t] = tree[2 * t] + tree[2 * t + 1];
			}
			cout << tree[1] << " ";
		}
		else if(qu.type == 2) {
			cout << f(1, qu.left, qu.right, 0, base - 1) << " ";
		}
		else {
			int x = base + qu.left;
			tree[x] = 0;
			for(int t = x / 2; t >= 1; t /= 2) {
				tree[t] = tree[2 * t] + tree[2 * t + 1];
			}
			cout << tree[1] << " ";
		}
	}
	//while(q--) {
		//int opt;
		//cin >> opt;
		//if(opt == 1) {
			//int i, v;
			//cin >> i >> v;
			//int x = base + i;
			//tree[x] += v;
			//for(int t = x / 2; t >= 1; t /= 2) {
				//tree[t] = tree[2 * t] + tree[2 * t + 1];
			//}
			//cout << tree[1] << " ";
		//}
		//else if(opt == 2) {
			//int l, r;
			//cin >> l >> r;
			//if(l > r)
				//swap(l, r);
			//cout << f(1, l, r, 0, base - 1) << " ";
		//}
		//else {
			//int i;
			//cin >> i;
			//int x = base + i;
			//tree[x] = 0;
			//for(int t = x / 2; t >= 1; t /= 2) {
				//tree[t] = tree[2 * t] + tree[2 * t + 1];
			//}
			//cout << tree[1] << " ";
		//}
	//}
    
}


int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	test_case();
	return 0;
}
