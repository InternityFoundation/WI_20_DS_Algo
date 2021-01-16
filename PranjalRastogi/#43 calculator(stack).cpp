class Solution {
public:
    int calculate(string s)
    {
        stack<int> stk;
        char sign= '+';
        int res= 0, tmp= 0;
        for(int i= 0; i< s.length(); i++){
            if(isdigit(s[i]))
                tmp= 10*tmp+s[i]-'0';
            if(!isdigit(s[i]) && !isspace(s[i]) || i == s.length()-1){
                if(sign == '-')
                    stk.push(-tmp);
                else if(sign == '+')
                    stk.push(tmp);
                else{
                    int num;
                    if(sign == '*')
                        num= stk.top()*tmp;
                    else
                        num= stk.top()/tmp;
                    stk.pop();
                    stk.push(num);
                }
                sign= s[i];
                tmp= 0;
            }
        }
        while(!stk.empty()){
            res+= stk.top();
            stk.pop();
        }
        return res;
    }
        
};
