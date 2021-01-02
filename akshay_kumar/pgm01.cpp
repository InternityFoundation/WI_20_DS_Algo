#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int n) {
    int ans = arr[0];
    for(int i = 1; i < n; i++) {
        ans ^= arr[i];
    }
    return ans;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
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
}
