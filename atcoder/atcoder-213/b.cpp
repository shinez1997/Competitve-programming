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
template<typename T> void dbg(vector<T> &v){cout << "["; for(T &i : v) cout << i << " "; cout << "]" << endl;};
template<typename T> void dbg(vector<vector<T>> &v){for(auto &i : v) dbg(i);};
#else
#define debug(...)
#define dbg(...)
#endif
void test_case() {

    
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& x : a)
		cin >> x;
	vector<int> order(n);
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&](int i, int j) {
		return a[i] < a[j];
	});
	order.pop_back();
	cout << order.back() + 1;
	return 0;
}
