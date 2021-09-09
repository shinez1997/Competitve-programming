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
const int nax = 1e4;
vector<int> isPrime;
void test_case() {
	string s;
	int n;
	cin >> n;
	cin >> s;
	
	vector<int> cnt(10);
	for(char c : s) 
		cnt[c-'0']++;
	for(int x : {1, 4, 6, 8, 9}) {
		if(cnt[x]) {
			cout << "1" << endl << x << endl;
			return;
		}
	}
    for(int i = 0; i < n; ++i){
		for(int j = i + 1; j < n; ++j) {
			string tmp = "";
			tmp += s[i];
			tmp += s[j];
			int t = stoi(tmp);
			if(!isPrime[t]) {
				cout << "2\n" << tmp << endl;
				return;
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	isPrime.assign(nax, 1);
	isPrime[1] = false;
	isPrime[0] = false;
	for(int i = 2; i < nax; ++i) {
		if(!isPrime[i])
			continue;
		for(int j = i * i; j < nax; j += i)
			isPrime[j] = 0;
	}
	//Debug(isPrime);
	int t;
    cin >> t;
    while(t--) test_case();
	return 0;
}
