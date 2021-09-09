#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve() {
    ll n, m, x;
    cin >> n >> m >> x;
    ll i = n  - x % n;
    
    ll j = x / n + 1;
    cout << "i: " << i << " j: " << j << endl; 
    ll ans = (j) + (i - 1) * m;
    cout << ans << endl;
}
int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}