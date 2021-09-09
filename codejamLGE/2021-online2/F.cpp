#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef pair<int, int> pii;
#define endl '\n'
#ifdef _LOCAL_
#define dbg(...) "[" << #__VA_ARGS__ ":" << (__VA_ARGS__) << "] "
template<typename T> void debug(vector<T> &v){for(T &i : v) cout << i << " ";cout << endl;};
template<typename T> void debug(priority_queue<T> q){while(!q.empty()) {cout << q.top() << " "; q.pop();}cout << endl;};
template<typename T> void debug(T x){cout << dbg(x) << endl;};
template<typename T, typename ...Arg> 
    void debug(T t, Arg... arg) {cout << dbg(t); debug(arg...);};
#else
#define debug(...)
#endif
priority_queue<int> min_in_sum, max_not_added;
vector<int> new_three;
ll takeSum(priority_queue<int> q, int k) {\
	ll ans = 0;
	for(int i = 0; i < k; ++i) {
		ans += q.top();
		q.pop();
	}
	return ans;
}
void solve() {
	int n;
	cin >> n;
	int k = n / 3;
	ll total_sum = 0;
	vector<int> v(n);
	priority_queue<int> q, p;
	new_three.resize(3, 0);
	vector<int> left(k + 1), right(k + 1); // left[i]: sum of i elements largest in 0->(3i - 1) right[i]: sum of i elements largest in n->(n + 1 -3i)
	int index;
	for(int i = 0; i < n; ++i) {
		cin >> v[i];
		total_sum += v[i];
		q.push(v[i]);
		new_three[i % 3] = v[i];
		if(i % 3 == 2) {
			if(i / 3 == 0) {
				vector<int> tmp ;
				for(int j = 0; j < 3; ++j) {
					tmp.push_back(v[j]);
					
				}
				sort(tmp.begin(), tmp.end());
				left[1] = tmp[2];
			}
			else if(i / 3 == 1) {
				vector<int> tmp ;
				for(int j = 0; j < 6; ++j) {
					tmp.push_back(v[j]);
					
				}
				sort(tmp.begin(), tmp.end());
				left[2] = tmp[4] + tmp[5];
			}
			else if(i / 3 == 2) {
				vector<int> tmp ;
				for(int j = 0; j < 9; ++j) {
					tmp.push_back(v[j]);
					
				}
				sort(tmp.begin(), tmp.end());
				left[3] = tmp[7] + tmp[8] + tmp[6];
				for(int j = 0; j < 6; ++j) 
					max_not_added.push(tmp[j]);
				for(int j = 6; j < 9; ++j) 
					min_in_sum.push(-tmp[j]);
			}
			else {
				//debug(min_in_sum);
				int a = -min_in_sum.top();
				min_in_sum.pop();
				int b = -min_in_sum.top();
				min_in_sum.pop();
				int c = -min_in_sum.top();
				min_in_sum.pop();
				int d = max_not_added.top();
				//cout << dbg(a) << dbg(b) << dbg(c) << dbg(d) << endl;
				max_not_added.pop();
				vector<int> seven_number;
				seven_number.push_back(new_three[0]);
				seven_number.push_back(new_three[1]);
				seven_number.push_back(new_three[2]);
				seven_number.push_back(a);seven_number.push_back(b);seven_number.push_back(c);seven_number.push_back(d);
				sort(seven_number.begin(), seven_number.end());
				ll sum_tmp = left[i/3] -(a+b+c);
				for(int j = 3; j < 7; ++j) {
					sum_tmp += seven_number[j];
					min_in_sum.push(-seven_number[j]);
				}
				for(int j = 0; j < 3; ++j) 
					max_not_added.push(seven_number[j]);
				left[i/3 + 1] = sum_tmp;
			}
		}
	}
	//debug(left);
	//debug(left1);
	reverse(v.begin(), v. end());
	priority_queue<int> min_in_sum_right, max_not_added_right;
	for(int i = 0; i < n; ++i) {
		new_three[i % 3] = v[i];
		if(i % 3 == 2) {
			if(i / 3 == 0) {
				vector<int> tmp ;
				for(int j = 0; j < 3; ++j) {
					tmp.push_back(v[j]);
					
				}
				sort(tmp.begin(), tmp.end());
				right[1] = tmp[2];
			}
			else if(i / 3 == 1) {
				vector<int> tmp ;
				for(int j = 0; j < 6; ++j) {
					tmp.push_back(v[j]);
					
				}
				sort(tmp.begin(), tmp.end());
				right[2] = tmp[4] + tmp[5];
			}
			else if(i / 3 == 2) {
				vector<int> tmp ;
				for(int j = 0; j < 9; ++j) {
					tmp.push_back(v[j]);
					
				}
				sort(tmp.begin(), tmp.end());
				right[3] = tmp[7] + tmp[8] + tmp[6];
				for(int j = 0; j < 6; ++j) 
					max_not_added_right.push(tmp[j]);
				for(int j = 6; j < 9; ++j) 
					min_in_sum_right.push(-tmp[j]);
			}
			else {
				int a = -min_in_sum_right.top();
				min_in_sum_right.pop();
				int b = -min_in_sum_right.top();
				min_in_sum_right.pop();
				int c = -min_in_sum_right.top();
				min_in_sum_right.pop();
				int d = max_not_added_right.top();
				//cout << dbg(a) << dbg(b) << dbg(c) << dbg(d) << endl;
				max_not_added_right.pop();
				vector<int> seven_number;
				seven_number.push_back(new_three[0]);
				seven_number.push_back(new_three[1]);
				seven_number.push_back(new_three[2]);
				seven_number.push_back(a);seven_number.push_back(b);seven_number.push_back(c);seven_number.push_back(d);
				sort(seven_number.begin(), seven_number.end());
				ll sum_tmp = right[i/3] -(a+b+c);
				for(int j = 3; j < 7; ++j) {
					sum_tmp += seven_number[j];
					min_in_sum_right.push(-seven_number[j]);
				}
				for(int j = 0; j < 3; ++j) 
					max_not_added_right.push(seven_number[j]);
				right[i/3 + 1] = sum_tmp;
			}
		}
	}
	reverse(v.begin(), v. end());
	//debug(right);
	//debug(right1);
	ll max_sum=0;
	for(int i = 0; i < n; i += 3) {
		int l = i / 3;
		ll tmp_sum = total_sum - left[l] - right[k - l];
		if(tmp_sum > max_sum) {
			max_sum = tmp_sum;
			index = i;
		}
	}
	cout << index << " " << max_sum << endl;
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
