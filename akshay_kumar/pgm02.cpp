#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int> &arr,int n) {
    int x, y;
    bool ans = false;
    for(int i = n; i > 0; i--) {
        x = arr[i]*arr[i];
        int low = 0; 
        int high = i-1;
        while(low < high) {
            y =  (arr[low]*arr[low] + arr[high]*arr[high]);
            if(x == y) {
                ans = true;
                break;
            } else {
                if(y < x) low++;
                else high--;
            }
        }
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

        bool ans = solve(arr, n);
        if(ans) {
            cout << "Triplet present\n";
        } else {
            cout << "Triplet not present\n";
        }
    }
    return 0;
}
