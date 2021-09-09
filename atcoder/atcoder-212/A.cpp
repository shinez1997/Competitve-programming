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
    int a, b;
    cin >> a >> b;
    if(!a)
		cout << "Silver";
	else if(!b)
		cout << "Gold";
	else
		cout << "Alloy";
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    test_case();
	return 0;
}
