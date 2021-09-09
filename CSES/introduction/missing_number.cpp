#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n - 1);
    for (int& i : arr) {
        cin >> i;
    }
    sort(arr.begin(), arr.end());
    int ans = 1;
    for (int i : arr) {
        if (i != ans)
            break;
        ans++;
    }
    cout << ans;
    return 0;
}