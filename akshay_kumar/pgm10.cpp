#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> arr, int n) {
   vector<int> sums(arr);
   int x, y;
    for(int i = n-3; i >= 0; i--)  {
        if(i + 2 < n)
            x = arr[i] + sums[i+2];
        if(i + 3 < n)
            y = arr[i] + sums[i+3];
        sums[i] = x > y ? x : y;
    }
    return sums[0] > sums[1] ? sums[0] : sums[1];
   
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> arr(n);
        for(auto i = arr.begin(); i < arr.end(); i++) {
            cin >> *i;
        }
        int ans = solve(arr, n);
        cout << ans << '\n';
    }
    return 0;
}
