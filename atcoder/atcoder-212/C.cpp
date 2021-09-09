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
void test_case() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int &x : a)
		cin >> x;
	for(int &x : b)
		cin >> x;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int i = 0, j = 0;
	int ans = 1e9 + 5;
	while(1) {
		if(i == n || j == m)
			break;
		ans = min(ans, abs(a[i] - b[j]));


		if(a[i] > b[j])
			j++;
		else
			i++;
		
	}
	cout << ans;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    test_case();
	return 0;
}
