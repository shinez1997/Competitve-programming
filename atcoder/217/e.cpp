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
#ifdef _LOCAL_
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define debug(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#define Debug(x) cout << #x << ": ["; for(auto& i : x) cout << i << " "; cout << "]" << endl;
#else
#define debug(...)
#define Debug(...)
#endif
void test_case() {
    int q;
    cin >> q;
    vector<int> a;
    multiset<int> s;
    while(q--) {
		int opt;
		cin >> opt;
		if(opt == 1) {
			int x;
			cin >> x;
			a.push_back(x);
		}
		else if(opt == 2) {
			if(s.empty()) {
				cout << a[0] << endl;
				a.erase(a.begin());
			}
			else {
				cout << *s.begin() << endl;
				s.erase(s.begin());
			}
		}
		else {
			for(int& x : a) 
				s.insert(x);
			a.clear();
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
