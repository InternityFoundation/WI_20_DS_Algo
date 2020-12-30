#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> arr, int n) {
    auto indx1 = is_sorted_until(arr.begin(), arr.end());
    auto last = indx1;  // last index till when arr was unsorted
    auto i = indx1;
    while(i < arr.end()) {
        i = is_sorted_until(i, arr.end());
        if(i == arr.end()) {
            break;
        } else {
            last = i;
        }
    }
    vector<int> ans = {(int)(indx1 - arr.begin() - 1), (int)(last - arr.begin())};
    return ans;
}

int main() {
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
        vector<int> ans = solve(arr, n);
        cout << ans[0] << ", " << ans[1] << '\n';
    }
    return 0;
}
