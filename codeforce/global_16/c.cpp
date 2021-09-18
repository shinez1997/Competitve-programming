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
	string s, t;
	cin >> s >> t;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		if(s[i] != t[i])
			a[i] = 2;
		else {
			a[i] = (s[i] == '0' ? 1 : 0);
		}
	}
	ll ans = 0;
	int i = 0;
	while(i < n) {
		//debug() << i;
		if(a[i] == 2) {
			ans += 2;
			i++;
		}
		else if(a[i] == 0) {
			if(i == n - 1)
				i++;
			else if(a[i+1] == 1) {
				ans += 2;
				i += 2;
			}
			else
				i++;
		}
		else if(a[i] == 1) {
			if(i == n -1) {
				++ans;
				i++;
			}
			else if(a[i+1] == 0) {
				ans += 2;
				i += 2;
			}
			else {
				ans++;
				i++;
			}
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
    while(t--) test_case();
	return 0;
}
