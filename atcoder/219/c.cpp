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
	string a;
	int n;
	cin >> a >> n;
	vi order(26);
	for(int i = 0; i < 26; ++i)
		order[a[i]-'a'] = i;
	vs s(n);
	for(string& x : s)	cin >> x;
	sort(s.begin(), s.end(), [&](string x, string y) {
		int l1 = x.size();
		int l2 = y.size();
		for(int i = 0; i < min(l1, l2); ++i) {
			if(order[x[i]-'a'] < order[y[i]-'a'])
				return true;
			if(order[x[i]-'a'] > order[y[i]-'a'])
				return false;
		}
		return l1 < l2;
	});
	for(string& x : s)
		cout << x << endl;
    
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	test_case();
	return 0;
}
