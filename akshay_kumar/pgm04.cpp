#include<bits/stdc++.h>
using namespace std;

void solve(string str, int n) {
    unordered_map<char, int> M;
    bool ans = true;
    char most = str[0];
    for(auto i = str.begin(); i < str.end(); i++) {
        if(M.find(*i) != M.end()) {
            M[*i]++;
            if(M[*i] > n / 2) {
                ans = false;
                break;
            }
        } else {
            M[*i] = 1;
        }
        if(M[*i] > M[most]) {
            most = *i;
        }
    }
    if(!ans) {
        cout << "None" << '\n';
    } else {
        string ans = "";
        for(int i = 0; i < M[most]; i++) {
            ans += most;
        }
        for(auto i = M.begin(); i != M.end(); i++) {
            if(i->first == most) continue;
            string c(1,i->first);
            int k = i->second;
            int indx = 1;
            for(int j = 0; j < k; j++) {
                ans.insert(indx, c);
                indx += 2;
            }
        }
        ans += '\0';
        cout << ans << '\n';
    }
    return;
}
