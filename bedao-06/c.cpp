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
const int mod = 727355608;
void test_case() {
	int n;
	cin >> n;
	string s(n, ' ');
	vector<int> a(4);
	a[0] = n;
	int cnt = 0;
	for(int i = 1; i < 4; ++i) {
		cin >> a[i];
		a[0] -= a[i];
		if(a[i] & 1)
			cnt++;
	}
	if(a[0] & 1)
		cnt++;
	bool ok = true;
	if(cnt > 1 && n != 1)
	{
		ok = false;
	}
	if(n & 1) {
		if(!cnt) {
			ok = false;
		}
		else 
		{
			for(int i = 0; i < 4; ++i) {
				if(a[i] & 1) {
					a[i]--;
					s[n/2] = char('0' + i);
				}
			}
		}
	}
	else {
		if(cnt)
			ok = false;
	}
	if(n == 1) {
		if(a[0]) {\
			ok = false;

		}
		else {
    		for(int i = 1; i < 4; ++i) 
    			if(a[i])
    				cout << i;
    		return;
		}
	}
	if(!ok) {
		cout << "Bedao!";
		return;
	}
	
    for(int i = 1; i < 4; ++i) {
		if(a[i] > 1) {
			ok = true;
			s[0] = s[n - 1] = char(i + '0');
			a[i] -= 2;
			break;
		}
	}
	if(s[0] != '1' || s[0] != '2' || s[0] != '3')
	{
		cout << "Bedao!";
		return;
	}
	//cout << s << endl;
	int cur = 1;
	for(int i = 0; i < 4; ++i) {
		while(a[i] > 1) {
			s[cur] = s[n - 1 - cur] = char(i + '0');
			a[i] -= 2;
			cur++;
		}
	}
	debug(s);
	ll base = 1;
	ll ans = 0;
	for(int i = 0; i < n; ++i) {
		ll d = int(s[i] - '0') * base;
		ans += d;
		ans %= mod;
		base *= 4;
		base %= mod;
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
