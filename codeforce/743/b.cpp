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
	int n;
	cin >> n;
	vi a(n), b(n);
	vi index(n);
	for(int& x : a) cin >> x;
	for(int& x : b) cin >> x;
	vi f(n); // index of element i in b (2->0, 4->1);
	for(int i = 0; i < n; ++i) {
		f[b[i]/2-1] = i;
	}
	for(int i = n - 2; i >= 0; --i) {
		f[i] = min(f[i], f[i+1]);
	}
	int best = 1e9 + 5;
	for(int i = 0; i < n; ++i) {
		best = min(best, i + f[(a[i] - 1)/2]);
	}
	cout << best << endl;
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
