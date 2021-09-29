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
void test_case() {
	int n, m;
	cin >> n >> m;
	vector<pii> a(m);
	for(pii &x : a) cin >> x.F >> x.S;
	sort(a.begin(), a.end(), [&](pii x, pii y) {
		if(x.F != y.F)
			return x.F < y.F;
		return x.S > y.S;
		});
	vi values;
	for(pii &x : a)	values.push_back(x.S);
	sort(values.begin(), values.end());
	values.resize(unique(values.begin(), values.end()) - values.begin());
	auto get = [&](int x) {
		return lower_bound(values.begin(), values.end(), x) - values.begin();
	};
    for(pii& x : a) x.S = get(x.S);
    int base = 1;
    m = values.size();
    while(base < m)
		base *= 2;
	int ans = 0;
	vi tree(2 * base);
	for(pii& x : a) {
		int k = x.S + base;
		int best = 0;
		while(k > 1) {
			if(k % 2 == 1)
				best = max(best, tree[k-1]);		
			k /= 2; 
		}
		ans = max(ans, best + 1);
		for(k = x.S + base; k >= 1; k /= 2) 
			tree[k] = max(tree[k], best + 1);
	}
	cout << ans;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	test_case();
	return 0;
}
