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
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	auto b = a;
	unordered_map<int, int> pos;
	sort(b.begin(), b.end());
	for(int i = 0; i < n; ++i) {
		pos[i] = b[i];
	}
	int cnt = 0;
	vector<tuple<int, int, int>> ans;
	for(int i = 0; i < n; ++i) {
		if(pos[i] == a[i]) {
			continue;
		}
		++cnt;
		int j = i + 1;
		while(a[j] != pos[i])
			j++;
		vector<int> tmp;
		for(int k = i; k <= j; ++k) {
			tmp.push_back(a[k]);
		}
		//debug() << imie(tmp);
		int d = j - i + 1;
		for(int k = i; k <= j; ++k) {
			//debug() << imie(k) imie(i) imie(j) imie(d);
			a[k] = tmp[((k - i + d - 1)%d)];
		}
		//debug() << imie(a);
		ans.emplace_back(i + 1, j + 1, j - i);
	}
	
	cout << cnt << endl;
	for(auto& x : ans) 
		cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << endl;

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
