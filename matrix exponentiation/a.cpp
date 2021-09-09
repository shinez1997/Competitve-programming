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
struct Matrix {
	double a[2][2] = {{0, 0}, {0, 0}};
	Matrix operator*(const Matrix& other) {
		Matrix product;
		for(int i = 0; i < 2; ++i) {
			for(int j = 0; j < 2; ++j) {
				for(int k = 0; k < 2; ++k) {
					product.a[i][k] += a[i][j] * other.a[j][k];
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
    double p;
    cin >> n >> p;
    Matrix total;
    for(int i = 0; i < 2; ++i) 
			total.a[i][i] = 1;
    Matrix one;
    one.a[0][0] = 1 - p;
    one.a[0][1] = p;
    one.a[1][0] = p;
    one.a[1][1] = 1 - p;
    while(n > 0) {
		if(n % 2 == 1) {
			total = total * one;
		}
		n /= 2;
		one = one*one;
	}
	printf("%.9f\n", total.a[0][0]);

	return 0;
}
