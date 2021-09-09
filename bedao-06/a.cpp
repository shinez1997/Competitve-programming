#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef pair<int, int> pii;
#define endl '\n'
#define ll long long 
#define F first
#define S second
#ifdef _LOCAL_
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define debug(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#define Debug(x) cout << #x << ": ["; for(auto& i : x) cout << i << " "; cout << "]" << endl;
#else
#define debug(...)
#define Debug(...)
#endif
void test_case() {
	double a, b, c, x, y;
	cin >> x >> y;
	debug(x, y);
	double delta = 4 * (x + y) * (x + y) - 4 * (y * y - x * x);
	//debug(delta);
	assert(delta >= 0);
	a = (x + y) - sqrt(delta) / 2;
	b = y - a;
	if(a < 0 || b < 0)
	{
		a = (x + y) + sqrt(delta) / 2;
		b = y - a;
	}
	c = a + x;
	if(a > b) swap(a, b);
	

	
	printf("%.9f %.9f %.9f", a ,b ,c);
    
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	test_case();
	return 0;
}
