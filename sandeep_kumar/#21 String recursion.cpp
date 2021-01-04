class Solution {
public:
    void reverse(vector <char>& s,int i){
        if(i==s.size()/2){
            return;
        }
        swap(s[i],s[s.size()-1-i]);
        reverse(s,i+1);
    }
    void reverseString(vector<char>& s) {
        reverse(s,0);
    }
};