class Solution {
public:
    int numSplits(string s) {
        int  n = s.size();
        int freq[26]={0};
        vector<int>left(n,0) , right(n,0);
        int count= 0 ;
        for(int i = 0 ; i < n; i++){
            if(freq[s[i]-'a'] ==  0){
                freq[s[i]-'a']+=1;
                count+=1;
            }
            left[i]= count;
            
        }
        memset(freq, 0 ,sizeof(freq));
         count = 0 ;
        for(int i =n-1 ; i >=0 ; i--){
            if(freq[s[i]-'a']==0){
                freq[s[i]-'a']+=1;
                count+=1;
            }
            right[i] = count;
        }
        int ans =  0;
        for(int i = 0;i < n-1 ; i++){
            if(left[i] == right[i+1])
                ans +=1;
        }
        return ans;
    }
};
