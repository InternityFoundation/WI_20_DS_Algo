class Solution {
public:
    bool isValid(string exp) 
    {
    
    stack<char> s;
    char h;
    
    int i=0;
    
    while(exp[i]!='\0')
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
        {
            s.push(exp[i]);
            i++;
            continue;
        }
        
        else if(exp[i]==')')
        {
            if(s.empty()==true)
            {
                return false;
            }
            char h=s.top();
            
            if(h=='(')
            {
              s.pop();
                i++;
                continue;
            }
            else
            {
                return false;
            }
        }
        
        else if(exp[i]=='}')
        {
            if(s.empty()==true)
            {
                return false;
            }
            char h=s.top();
            
            if(h=='{')
            {
              s.pop();
                i++;
                continue;
            }
            else
            {
                return false;
            }
        }
        
        else if(exp[i]==']')
        {
            
         if(s.empty()==true)
            {
                return false;
            }
            
            char h=s.top();
            
            if(h=='[')
            {
              s.pop();
                i++;
                continue;
            }
            else
            {
                return false;
            }
        }
        else
        {
            i++;
        }
    }
    
    if(s.empty()==true)
        return true;
    else
        return false;
    
        
    }
};
