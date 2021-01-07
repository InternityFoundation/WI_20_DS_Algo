class Solution {
public:
    bool isValid(string &s){
        if(s.size()>3){
            return false;
        }
        if(s[0]=='0' && s.size()>1){
            return false;
        }
        if(stoi(s)>=0 && stoi(s)<=255){
            return true;
        }
        return false;
    }
    vector<string> restoreIpAddresses(string s) {
        
        vector <string> ans;
        for(int i=1;i<s.size() && i<4;i++){
            string first=s.substr(0,i);
            if(isValid(first)){
                for(int j=1;i+j<s.size() && j<4;j++){
                    string second = s.substr(i,j);
                    if(isValid(second)){
                        for(int k=1;i+j+k<s.size() && k<4;k++){
                            string third=s.substr(i+j,k),fourth=s.substr(i+j+k);
                            if(isValid(third) && isValid(fourth)){
                                ans.push_back(first+"."+second+"."+third+"."+fourth);
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};