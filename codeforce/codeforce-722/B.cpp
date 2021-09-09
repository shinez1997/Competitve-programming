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
    for(int &x : arr)
        cin >> x;
    sort(arr.begin(), arr.end());
    int diff;
    int ans = 0;
    for(int i = n - 1; i >= 0; --i) {
        diff = arr[i];
        int cnt = 1; 
        int prev = arr[i];
        for(int j = i - 1; j >= 0; --j) {
            if(prev - arr[j] >= diff) {
                cnt++;
                prev = arr[j];
            }
        }
        ans = max(ans, cnt);
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
