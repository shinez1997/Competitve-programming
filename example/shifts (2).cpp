
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
/*
 Google kickstart round G-2019
*/
vector<int> a, b;
vector<pii> v;
const int INF = 1e9 + 5;
void rec(int i, int limit, long long A, long long B) {
	if(i == limit) {
		v.emplace_back((int) min((ll) INF, A), (int) min((ll) INF, B));
		return;
	}
	rec(i + 1, limit, A + a[i], B);
	rec(i + 1, limit, A, B + b[i]);
	rec(i + 1, limit, A + a[i], B + b[i]);
}
const int QUERY = 0, POINT = 1;
struct Event {
	int x, y, type;
	bool operator <(const Event &he) const {
		return make_pair(x, make_pair(y, type)) > make_pair(he.x, make_pair(he.y, he.type));
	}
};
void test_case() {
	int n, h;
	cin >> n >> h;
	a.clear();
	a.resize(n);
	b.clear();
	b.resize(n);
	
	
	for(int& x : a) cin >> x;
	for(int& x : b) cin >> x;
    int mid = n / 2;
    //debug() << imie(mid);
    rec(0, mid, 0LL, 0LL);
    vector<pii> L = v;
    v.clear();
    rec(mid, n, 0LL, 0LL);
	vector<pii> R = v;
	v.clear();
	//debug() << imie(L) imie(R);
	vector<Event> events; 
	for(pii e : L) {
		int x = max(0, h - e.F);
		int y = max(0, h - e.S);
		events.push_back(Event{x, y, QUERY});
	}
	for(pii e : R)
		events.push_back(Event{e.F, e.S, POINT});
	vector<int> values;
	for(auto e : events) {
		values.push_back(e.x);
		values.push_back(e.y);
	}
	sort(values.begin(), values.end());
	values.resize(unique(values.begin(), values.end()) - values.begin());
	
	auto get = [&](int x) {
		return lower_bound(values.begin(), values.end(), x) - values.begin();
	};
	
	for(auto& e : events) {
		e.x = get(e.x);
		e.y = get(e.y);
	}
	sort(events.begin(), events.end());
	int base = 1;
	while(base <= (int)values.size())
		base *= 2;
	ll ans = 0;
	vector<int> tree(2 * base);
	for(auto e : events) {
		int y = e.y;
		if(e.type == QUERY) {
			ans += tree[y + base];
			for(int i = (y + base); i >= 2; i /= 2)
				if(i % 2 == 0)
					ans += tree[i+1];
		}
		else {
			for(int i = (y + base); i >= 2; i /= 2)
				tree[i]++;
		}
	}
	cout << ans << endl;
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
