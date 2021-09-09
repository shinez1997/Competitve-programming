#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef pair<int, int> pii;
#define endl '\n'
#define ll long long 
#ifdef _LOCAL_
#define dbg(...) "[" << #__VA_ARGS__ ":" << (__VA_ARGS__) << "] "
template<typename T> void debug(vector<T> &v){for(T &i : v) cout << i << " ";cout << endl;};
#else
#define debug(...)
#endif
const int mod = 1e9 + 7;


struct Matrix {
	ll a[2][2];
	Matrix(){
		a[0][0] = 0;
		a[0][1] = 0;
		a[1][0] = 0;
		a[1][1] = 0;
	}
	Matrix operator*(const Matrix& other) {
		Matrix product;
		for(int i = 0; i < 2; ++i) {
			for(int j = 0; j < 2; ++j) {
				for(int k = 0; k < 2; ++k) {
					product.a[i][k] += a[i][j] * other.a[j][k];
					product.a[i][k] %= mod;
				}
			}
		}
		return product;
	}
};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int n;
    cin >> n;
    Matrix total;
    for(int i = 0; i < 2; ++i) 
			total.a[i][i] = 1;
    Matrix one;
    one.a[0][0] = 19;
    one.a[0][1] = 7;
    one.a[1][0] = 6;
    one.a[1][1] = 20;
    while(n > 0) {
		if(n % 2 == 1) {
			total = total * one;
		}
		n /= 2;
		one = one*one;
	}
	cout << total.a[0][0];

	return 0;
}
