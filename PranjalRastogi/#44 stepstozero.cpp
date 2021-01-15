class Solution {
public:
    int numberOfSteps (int num) 
    {
        if(num>=1)
        {
            if(num%2==0)
                return numberOfSteps(num/2)+1;
            else
                return numberOfSteps(num-1)+1;
        }
        return 0;   
        
    }
};
