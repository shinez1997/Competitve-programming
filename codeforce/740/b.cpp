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
	int a, b;
	cin >> a >> b;
	int sum = a + b;
	if(a > b)
		swap(a, b);
	vector<int> ans;
	if(sum % 2 == 0) {
		int n = sum / 2;
		int L = n - a;
		int R = n + a;
		for(int i = L; i <= R; i += 2)
			ans.push_back(i);
	}
    else {
		int n = sum / 2;
		int L = n - a;
		int R = n + a;
		for(int i = L; i <= R + 1; ++i) {
			ans.push_back(i);
		}
	}
	cout << ans.size() << endl;
	for(int& x : ans)
		cout << x << " ";
	cout << endl;
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
