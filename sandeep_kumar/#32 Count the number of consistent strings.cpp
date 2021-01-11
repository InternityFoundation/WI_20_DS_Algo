class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int allowedchars[26]={0};
        for(int i=0;i<allowed.size();i++){
            allowedchars[(int)allowed[i]-97]=1;
        }
        int count=0;
        for(int i=0;i<words.size();i++){
            int j;
            for(j=0;j<words[i].size();j++){
                if(allowedchars[(int)words[i][j]-97]==0)
                    break;
                if(j==words[i].size()-1){
                    count++;
                }
            }
        }
        return count;
    }
};