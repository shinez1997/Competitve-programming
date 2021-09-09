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

int nax = 1e5 + 5;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<bool> isPrime = vector<bool>(nax, true);
	vector<int> p;
	for(int i = 2; i < nax; ++i) {
		if(!isPrime[i])
			continue;
		p.push_back(i);
		for(int j = i; j < nax; j += i) 
			isPrime[j] = false;
	}
	//cout << n;
	//Debug(p);
	vector<bool>used(p.size());
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		for(int j = 0; j < (int)p.size(); ++j) {
			if(p[j] > m)
				break;
			while(x % p[j] == 0) {
				x /= p[j];
				used[j] = true;
			}
		}
	}
	vector<int> ans;
	for(int i = 0; i < (int)p.size(); ++i) {
		if(p[i] > m)
			break;
		if(used[i])
			continue;
		ans.push_back(p[i]);
	}
	cout << ans.size() + 1<< endl;
	cout << "1\n";
	for(int& x : ans)
		cout << x << endl;
	return 0;
}
