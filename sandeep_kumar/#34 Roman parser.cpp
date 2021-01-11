class Solution {
public:
    int romanToInt(string s) {
        map<char,int> M={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int ans=0;
        if(s.size()==1){
            return M[s[0]];
        }
        int i=s.size()-2,p=s.size()-1;
        ans=M[s[p]];
        do{
            if(M[s[i]]<M[s[p]]){
                ans-=M[s[i]];
            }
            else if(M[s[i]]>=M[s[p]]){
                ans+=M[s[i]];                
            }
            p--;
        }while(i--);
        return ans;
    }
};