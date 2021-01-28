class Solution {
public:
    int numSplits(string s) {
        int count=0;
        if(s.size()==1){
            return count;
        }
        set <char> S1,S2;
        int from_front[s.size()];
        int from_back[s.size()];
        
        for(int i=0;i<s.size();i++){
            S1.insert(s[i]);
            S2.insert(s[s.size()-1-i]);
            from_front[i]=S1.size();
            from_back[s.size()-1-i]=S2.size();
        }
        for(int i=0;i<s.size()-1;i++){
            if(from_front[i]==from_back[i+1]){
                count++;
            }
        }
        return count;
    }
};