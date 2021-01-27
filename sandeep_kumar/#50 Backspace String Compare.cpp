class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string s1,s2;
        for(int i=0;i<S.size();i++){
            if(S[i] == '#'){
                if(s1.size()==0){
                    
                }
                else{
                s1.pop_back();                    
                }
            }
            else{
            s1.push_back(S[i]);                
            }
        }
        for(int i=0;i<T.size();i++){
            if(T[i] == '#'){
                if(s2.size()==0){
                    
                }
                else{
                s2.pop_back();                    
                }
            }
            else{
                s2.push_back(T[i]);    
            }
        }
        return s1==s2;
    }
};