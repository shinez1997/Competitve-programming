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
#else
#define debug(...)
#endif
void solve() {
    int n;
    cin >> n;
    vi arr(n);
    int min_e = 1e9;
    for(int &x : arr) {
        cin >> x;
        min_e = min(min_e, x);
    }
    int cnt = 0;
    for(int x : arr) {
        if(x == min_e)
            cnt++;
    }
    cout << n - cnt << endl;
    
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
