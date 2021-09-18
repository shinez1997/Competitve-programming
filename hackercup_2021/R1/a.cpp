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
const int L = 0, R = 1;

const int mod = 1e9 + 7;
void add(int& a, int b) {
	a += b;
	if(a >= mod)
		a-=mod;
	if(a < 0)
		a += mod;
}
void test_case() {
	int n;
	string s;
	cin >> n >> s;
	vector<int> pref(n);
	vector<int> suf(n);
	pref[0] = 0;
	int ans = 0;
	{
		int cur = -1;
		if(s[n-1] == 'O')
			cur = 0;
		if(s[0] == 'X')
			cur = 1;
		for(int i = n - 2; i >= 0; --i) {
		suf[i] = suf[i+1];
		if(s[i] == 'O') {
			if(cur == 1) {
				add(suf[i], 1);
				
			}
			cur = 0;
		}
		else if(s[i] == 'X') {
			if(cur == 0) {
				add(suf[i], 1);
				
			}
			cur = 1;
		}
		}
	}
	int cur = -1;
	if(s[0] == 'O')
		cur = 0;
	if(s[0] == 'X')
		cur = 1;
	for(int i = 1; i < n; ++i) {
		pref[i] = pref[i-1];
		if(s[i] == 'O') {
			if(cur == 1) {
				add(pref[i], 1);
			}
			cur = 0;
		}
		else if(s[i] == 'X') {
			if(cur == 0) {
				add(pref[i], 1);
			}
			cur = 1;
		}
		add(ans, pref[i]);
		for(int j = i - 1; j >= 1; --j) {
			add(ans, min(suf[j] - suf[i], pref[i] - pref[j]));
		}
	}
	
	cout << ans << endl;
	debug() << imie(pref) imie(suf);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		test_case();
	}
	return 0;
}

