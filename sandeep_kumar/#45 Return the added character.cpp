class Solution {
public:
    char findTheDifference(string s, string t) {
        if(s.size()==0){
            return t[0];
        }
        int shash[26]={0};
        int thash[26]={0};
        for(int i=0;i<s.size();i++){
            shash[(int)s[i]-97]++;
        }
        for(int i=0;i<t.size();i++){
            thash[(int)t[i]-97]++;
        }
        for(int i=0;i<26;i++){
            if(thash[i]!=shash[i]){
               return (char)i+97;               
            }
        }
        return t[t.size()-1];
    }
};