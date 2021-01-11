class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector <int> ans={};
        if(p.size()>s.size()){
            return ans;
        }
        int shash[26]={0};
        int phash[26]={0};
        for(int i=0;i<p.size();i++){
            phash[(int)p[i]-97]++;
        }
        for(int j=0;j<p.size();j++){
            shash[(int)s[j]-97]++;
        }
        int k;
        for(k=0;k<26;k++){
            if(shash[k]!=phash[k])
                break;
        }
        if(k==26)
            ans.push_back(0);
        
        for(int i=1;i<=s.size()-p.size();i++){
            shash[(int)s[i-1]-97]--;
            shash[(int)s[i+p.size()-1]-97]++;
            
            for(k=0;k<26;k++){
                if(shash[k]!=phash[k])
                    break;
            }
            if(k==26)
                ans.push_back(i);
        }
        
        return ans;
    }
    
};