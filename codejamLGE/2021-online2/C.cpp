#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef pair<int, int> pii;
#define endl '\n'
#ifdef _LOCAL_
#define dbg(...) "[" << #__VA_ARGS__ ":" << (__VA_ARGS__) << "] "
template<typename T> void debug(vector<T> &v){for(T &i : v) cout << i << " ";cout << endl;};
#else
#define dbg(...)
#define debug(...)
#endif
#define MAX_I 100100
bool isPrime[MAX_I];
vector<long long> prime;
int l;
ll getmin(vector<long long> a, vector<long long> b) {
	ll sum = 0;
	for(int i = 0; i < (int)a.size(); ++i) {
		sum += abs(a[i]-b[i]);
	}
	return sum;
}
void solve() {
	int n;
	cin >> n;
	ll ans = 1e9;
	vector<long long> v(n);
	for(ll &i : v) {
		cin >> i;
	}
	sort(v.begin(), v.end());
	int low  = upper_bound(prime.begin(), prime.end(), v[0]) - prime.begin();
	int up  = lower_bound(prime.begin(), prime.end(), v[n - 1]) - prime.begin();
	//cout << dbg(low) << dbg(up);
	for(int i = 0; i < l; ++i) {
		vector<long long> test(n);
		for(int j = 0; j < n; ++j) {
			test[j] = prime[i + j];
		}
		ans = min(ans, getmin(test, v));
	}
	cout << ans << endl;

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(isPrime, 1, sizeof isPrime);
	isPrime[0] = 0;
	isPrime[1] = 0;
	for(ll i = 2; i * i <= MAX_I; ++i) {
		if(isPrime[i] == 0)
			continue;
		for(int j = 2 * i; j <= MAX_I; j += i) {
			isPrime[j] = 0;
		}
	}
	for(ll i = 2; i <= MAX_I; ++i) {
		if(isPrime[i])
			prime.push_back(i);
	}
	l = prime.size();
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
