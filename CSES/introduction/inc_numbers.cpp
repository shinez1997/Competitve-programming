#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &i : arr) {
        cin >> i;
    }
    long long ans = 0;
    for(int i = 0; i < (n - 1); ++i) {
        if(arr[i] > arr[i + 1]) {
            ans += (long long)(arr[i] - arr[i + 1]);
            arr[i + 1] = arr[i];
        }
    }
    cout << ans;
    return 0;
}