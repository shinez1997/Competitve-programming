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
	int h, w, n;
	cin >> h >> w >> n;
	vector<int> row;
	vector<int> col;
	vector<pii> p(n);
	for(int i = 0; i < n; ++i) {
		cin >> p[i].F >> p[i].S;
		row.push_back(p[i].F);
		col.push_back(p[i].S);
	}
	//dbg(row); 
	//dbg(col);
	sort(p.begin(), p.end());
	sort(row.begin(), row.end());
	sort(col.begin(), col.end());
	unordered_map<int, int> row_pos, col_pos;

	for(int i = 0; i < (int)row.size(); ++i) {
		row_pos[row[i]] = i + 1;
	}
	for(int i = 0; i < (int)col.size(); ++i) {
		col_pos[col[i]] = i + 1;
	}
	for(pii& x : p) {
		cout << row_pos[x.F] << " " <<  col_pos[x.S] << endl;
	}
	return 0;
}
