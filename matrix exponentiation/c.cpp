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
	Matrix() {
		for(int i = 0; i < 2; ++i) 
			for(int j = 0; j < 2; ++j) 
				a[i][j] = 0;
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
    ll n;
    cin >> n;
    Matrix f;
    Matrix single;
    // new_a = 0*a + 1*b
    // new_b = 1*a + 1*b;
    single.a[0][0] = 0;
	single.a[0][1] = 1;
	single.a[1][0] = 1;
	single.a[1][1] = 1;
	Matrix ans = single;
	if(n == 0)
	{
		cout << "0";
		return 0;
	}
	n--;
	while(n > 0) {
		if(n % 2)
			ans = ans * single;
		n /= 2;
		single = single * single;
	}
	//two = two * single;
	cout << ans.a[1][0];
	return 0;
}
