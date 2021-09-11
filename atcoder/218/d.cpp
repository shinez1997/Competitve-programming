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
	int n;
	cin >> n;
    vector<pii> point(n);
    vector<int> values;
    for(pii &p : point) {
		cin >> p.F >> p.S;
		values.push_back(p.F);
		values.push_back(p.S);
	}
	sort(values.begin(), values.end());
	values.resize(unique(values.begin(), values.end()) - values.begin());
	auto get = [&](int x) {
		return lower_bound(values.begin(), values.end(), x) - values.begin();
	};
	int m = values.size();
	vector<vector<int>> xPoint(m);
	for(auto& p : point) {
		p.F = get(p.F);
		p.S = get(p.S);
		xPoint[p.F].push_back(p.S);
	}
	for(int i = 0; i < m; ++i) {
		sort(xPoint[i].begin(), xPoint[i].end());
	}
	ll ans = 0;
	for(int i = 0; i < m; ++i) {
		if(xPoint[i].size() < 2)
			continue;
		for(int j = i + 1; j < m; ++j) {
			if(xPoint[j].size() < 2)
				continue;
			ll cnt = 0;
			for(int x : xPoint[i]) {
				if(*lower_bound(xPoint[j].begin(), xPoint[j].end(), x) == x)
					++cnt;
			}
			ans += cnt * (cnt - 1) / 2;
		}
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
