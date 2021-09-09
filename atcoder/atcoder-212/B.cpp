#include <bits/stdc++.h>

using namespace std;
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
bool check(char a, char b) {
	int i = a - '0';
	int j = b - '0';
	if(j == ((i + 1) % 10))
		return true;
	return false;
}
bool test_case() {
    string s;
    cin >> s;
    if(s[0] == s[1] && s[1] == s[2] && s[2] == s[3])
		return false;
	if(check(s[0], s[1]) && check(s[1], s[2]) && check(s[2], s[3]))
		return false;
	return true;
}


main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    if(test_case())
		cout << "Strong\n";
	else 
		cout << "Weak\n";
	return 0;
}
