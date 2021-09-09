#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef pair<int, int> pii;
#define endl '\n'
#ifdef _LOCAL_
#define dbg(...) "[" << #__VA_ARGS__ ":" << (__VA_ARGS__) << "] "
template<typename T> void debug(vector<T> &v){for(T &i : v) cout << i << " ";cout << endl;};
template<typename T> void debug(T x){cout << dbg(x) << endl;};
template<typename T, typename ...Arg> 
    void debug(T t, Arg... arg) {cout << dbg(t); debug(arg...);};
#else
#define debug(...)
#endif
void solve() {
	char ans;
	int a, b, c;
	cin >> a >> b >> c;
	int k = 10;
	vector<int> cnt;
	cnt.push_back(0);
	while(k <= 1e13) {
		int i = (k - a) / b;
		if(i < 0) i = 0;
		cnt.push_back(i);
		k *= 10;
	}
	int n = cnt.size();
	vector<int> sum(n);
	sum[0] = cnt[0];
	for(int i = 1; i < n; ++i) {
		sum[i] += sum[i - 1] + (i) * (cnt[i] - cnt[i -1]);
	}
	//debug(cnt);
	//debug(sum);
	int index = 0;
	for(int i = 0; i < n; ++i) {
		if(sum[i] < c) 
			index = i;
		else
			break;
	}
	c -= sum[index];
	index++;
	if(c % (index) == 0) {
		k = c /(index);
		k += cnt[index -1] - 1;
		string number = to_string(k * b + a);
		//cout << number << endl;
		ans = number[index - 1];
	}
	else {
		k = c /(index);
		c -= k *(index);
		k += cnt[index -1]+1;
		string number = to_string(k * b + a);
		ans = number[c-1];
	}
	cout << ans << endl;
}


main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
