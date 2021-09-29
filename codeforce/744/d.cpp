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
	set<pii> a;
	for(int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		a.insert(make_pair(x, i));
	}
	vector<pii> ans;
	while(1) {
		auto f = a.begin();
		auto s = a.end();
		s--;
		if(a.size() < 2)
			break;
		if(f != s) {
			ans.emplace_back((*f).S, (*s).S);
			auto p1 = *f;
			auto p2 = *s;
			
			a.erase(p1);
			a.erase(p2);
			p1.F--;
			p2.F--;
			if(p1.F > 0)
				a.insert(p1);
			if(p2.F > 0)
			a.insert(p2);		
		}
		else {
			break;
		}
	}
	cout << ans.size() << endl;
	for(pii& x : ans)
		cout << x.F << " " << x.S << endl;
    
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
