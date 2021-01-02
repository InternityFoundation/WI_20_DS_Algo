#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &arr, int target, int n) {
    int x, y;
    vector<int> ans(2);
    unordered_map<int, int> M;
    for(int i = 0; i < n; i++) {
        x = arr[i];
        y = target - x;
        if(M.find(y) != M.end()) {
            ans[0] = i;
            ans[1] = M[y];
            break;
        } else {
            M[x] = i;
        }
    }
    return ans;    
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t, n, target;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> arr(n);
        for(auto i = arr.begin(); i < arr.end(); i++) {
            cin >> *i;
        }
        cin >> target;
        vector<int> ans = solve(arr, target, n);
        cout << ans[0] << ',' << ans[1] << '\n';
    }
    return 0;
}
