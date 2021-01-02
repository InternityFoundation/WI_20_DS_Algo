#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> arr, int n) {
    priority_queue<int, vector<int>, greater<>> Q;
    for(auto i : arr) {
        Q.push(i*i);
    }
    vector<int> ans;
    while(!Q.empty()) {
        int x = Q.top();
        Q.pop();
        ans.emplace_back(x);
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
        vector<int> arr(n);
        for(auto i = arr.begin(); i < arr.end(); i++) {
            cin >> *i;
        }
        vector<int> ans = solve(arr, n);
        for(auto i : ans) {
            cout << i << " ";
        }
        cout << '\n';
    }
    return 0;
}
