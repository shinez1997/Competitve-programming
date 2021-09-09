#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef pair<int, int> pii;
#define endl '\n'
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef _LOCAL_
#define debug(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define debug(...)
#endif
#define F first
#define S second
void solve() {
		int n, x;
        cin >> n >> x;
        long long hs, ha, hb, hc;
        long long ws, wa, wb, wc;
        cin >> hs >> ha >> hb >> hc;
        cin >> ws >> wa >> wb >> wc;

        vector<long long> H(n), W(n);
        H[0] = hs % hc + 1;
        W[0] = ws % wc + 1;
        for (int i=1; i<=n-1; i++) {
            H[i] = H[i-1] + 1 + (H[i-1] * ha + hb) % hc;
            W[i] = (W[i-1] * wa + wb) % wc + 1;
        }
        for (int i=0; i<=n-1; i++) {
            W[i] *= H[i];
        }
        ll ans = -1;
        deque<int> dq;
        for(int i = 0; i < n; ++i) {
			if(!dq.empty() && H[i] - H[dq.front()] > x)
				dq.pop_front();
			if(!dq.empty())
				ans = max(ans, W[dq.at(0)] + W[i]);
			while(!dq.empty() && W[i] > W[dq.back()]) {
				dq.pop_back();
			}		
			dq.push_back(i);
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
