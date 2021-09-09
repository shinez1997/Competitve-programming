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
	int L, Q;
	cin >> L >> Q;
	set<int> cut;
	cut.insert(L);
	cut.insert(0);
	//cout << "set: ";
	//for(auto iter = cut.begin(); iter != cut.end(); ++iter) {
		//cout << *iter << " ";
	//}
	//cout << endl;
	while(Q--) {
		int opt, x;
		cin >> opt >> x;
		if(opt == 1) {
			cut.insert(x);
		}
		else {
			auto left = cut.lower_bound(x);// - cut.begin();
			left--;
			auto right = cut.upper_bound(x);// - cut.begin();
			//debug(*right, *left);
			cout << *right - *left << endl;
		}	
		//cout << "set: ";
		//for(auto iter = cut.begin(); iter != cut.end(); ++iter) {
			//cout << *iter << " ";
		//}
		//cout << endl;
	}
    
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	test_case();
	return 0;
}
