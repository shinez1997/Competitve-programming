#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Trie {
	Trie* child[2];
	Trie() {
		child[0] = NULL;
		child[1] = NULL;
		val = 0;
	}
	int val;

};
void insert(Trie *root, int v) {

	    ++root->val;
		bitset<32> bs(v);
		for(int i = 31; i >= 0; --i) {
			int bit = bs[i] & 1;
			if(root->child[bit] == NULL) {
				root->child[bit] = new Trie();
			}
			root = root-> child[bit];
			++root->val; 
		}
	
}
int find_min(Trie * root, int v) {
    //cout << "find_min " << v << endl;
	int ans = 0;
	bitset<32> bs(v);
	for(int i = 31; i >= 0; --i) {
		int bit = bs[i] & 1;
		if(root->child[bit] == NULL || root->child[bit]->val == 0) {
			ans |= (1LL <<i);
			root = root->child[bit^1];
		}
		else {
			root = root->child[bit];
		}
	}
	return ans;
}
int find_max(Trie * root, int v) {
    //cout << "find_max " << v << endl;
	int ans = 0;
	bitset<32> bs(v);
	for(int i = 31; i >= 0; --i) {
		int bit = bs[i] & 1;
		if(root->child[bit^1] == NULL || root->child[bit^1]->val == 0) {
		    root = root->child[bit];
			
		}
		else {
			ans |= (1LL <<i);
			root = root->child[bit^1];
		}
	}
	return ans;
}

int deleteMax(Trie * root) {
    --root->val;
    int ans = 0;
	for(int i = 31; i >= 0; --i) {
		if(root->child[1] != NULL && root->child[1]->val != 0) {
			root = root->child[1];
			ans |= (1LL) << i;
		}
		else {
			root = root->child[0];
		}
		--root->val;
	}
	cout << ans << endl;
	return ans;
}
int deleteMin(Trie * root) {
    --root->val;
    int ans = 0;
	for(int i = 31; i >= 0; --i) {
		if(root->child[0] != NULL && root->child[0]->val != 0) {
			root = root->child[0];
		}
		else {
			root = root->child[1];
			ans |= (1LL) << i;
		}
		--root->val;
	}
	cout << ans << endl;
	return ans;
}
void solve() {
	int n, q;
	set<int> mySet;
	cin >> n >> q;
	int val;
	Trie* root = new Trie();
	for(int i = 0; i < n; ++i) {
	    cin >> val;
	    if(!mySet.count(val)) {
			insert(root, val);
			mySet.insert(val);
		}
	}
	int c, v;
	for(int i = 0; i < q; ++i) {
		cin >> c;
		if(c == 1) {
			cin >> v;
			cout << find_min(root, v) << endl;
		}
		if(c == 2) {
			cin >> v;
			cout << find_max(root, v) << endl;
		}
		if(c == 3) {
			cin >> v;
			if(!mySet.count(v))
				insert(root, v);
			cout << root->val << endl;
		}
 		if(c == 4) {
 		    int rm = deleteMin(root);
 		    mySet.erase(rm);
 		    //cout << "root: " << root->val << endl;
 		}
 		if(c == 5) {
 		    int rm = deleteMax(root);
 		    mySet.erase(rm);
 		    //cout << "root: " << root->val << endl;
 		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)	solve();
	return 0;
}
