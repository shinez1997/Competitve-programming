#include <iostream>
#include <unordered_set>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    set<int> arr;
    int n;
    cin >> n;
    int x;
    for(int i = 0; i < n; ++i) {
        cin >> x;
        arr.insert(x);
    }
    cout << arr.size();
    return 0;
}