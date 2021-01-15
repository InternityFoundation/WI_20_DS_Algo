class Solution {
public:
    char findTheDifference(string s, string t)
    {
        map<char,int> count;
        for(int i=0;i<s.size();i++)
            count[s[i]]++;
        for(int i=0;i<t.size();i++)
        {
            count[t[i]]--;
            if(count[t[i]]==-1)
               return t[i];
        }
        
        return NULL;

        
    }
};
