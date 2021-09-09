#include <bits/stdc++.h>

using namespace std;
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
const int mod = 998244353;
void add_self(int&a, int b) {
    a += b;
    if(a >= mod) {
        a -= mod;
    }
}
int mul(int a, int b) {
    return  a * b % mod;
}

int n;
struct M {
    vector<vector<int>> t;
    M() {
        t.resize(n, vector<int>(n));
    }
    M operator* (const M& b) const {
        M c = M();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                for(int k = 0; k < n; ++k) {
                    add_self(c.t[i][k], mul(t[i][j], b.t[j][k]));
                }
            }
        }
        return c;
    }
};
int main() { 
	int  s , k;
	cin >> n >> s >> k;
	vector<vector<int>> can(n, vector<int>(n, 1));
	for(int i = 0; i <s; ++i) {
		int u, v;
		cin >> u >> v;
		can[u-1][v-1] = 0;
		can[v-1][u-1] = 0;
	}
	for(int i = 0; i <n; ++i)
		can[i][i] = 0;
	M answer = M();
    for(int i = 0; i < n; ++i) {
        answer.t[i][i] = 1;
    }
    M m = M();
    m.t = can;
    while(k) {
        if(k % 2) {
            answer = answer * m;
        }
        m = m * m;
        k /= 2;
    }
    cout << answer.t[0][0];
    return 0;
}
