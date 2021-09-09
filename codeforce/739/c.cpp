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
	int r, c;
	int offSet = sqrt(n - 1); // offSet: thu tu cua diem can tim
    int maxNum = (offSet + 1) * (offSet + 1);
    int minNum = offSet * offSet + 1;
    int mid = maxNum - offSet;
    //debug(n, offSet, maxNum, minNum, mid);
    if(n > mid) { // diem do nam o hang ngang offSet + 1
		r = offSet + 1;
		c = maxNum - n + 1;
	}
	else { // diem se nam o cot offSet + 1
		c = offSet + 1;
		r = n - minNum + 1;
	}
	cout << r << " " << c << endl;
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
