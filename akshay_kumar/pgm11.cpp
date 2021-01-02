#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> arr, int k, int n) {
   sort(arr.begin(), arr.end());
   int low = 0;
   int high = n-1;
   int count = 0;
   while(low < high) {
       if(arr[low] + arr[high] <= k) {
           low++;
           high--;
       } else {
           high--;
       }
       count++;
   }
   if(low == high) count++;
   return count;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, k;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> arr(n);
        for(auto i = arr.begin(); i < arr.end(); i++) {
            cin >> *i;
        }
        cin >> k; 
        int ans = solve(arr, k, n);
        cout << ans << '\n';
    }
    return 0;
}
