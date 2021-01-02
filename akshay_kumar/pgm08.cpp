#include<bits/stdc++.h>
using namespace std;

bool solve(int num) {
    bool ans = true;
    int d, n = num;
    vector<int> arr;
    while(n > 0) {
        d = n % 10;
        n = n / 10;
        arr.emplace_back(d);
    }
    int low = 0, high = arr.size()-1;
    while(low < high) {
        if(arr[low] != arr[high]) {
            ans= false;
            break;
        } else {
            low++;
            high--;
        }
    }
    return ans;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        cout << solve(n) << '\n';
    }
    return 0;
}
