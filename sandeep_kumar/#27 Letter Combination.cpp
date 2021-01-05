class Solution {
public:
    map <char,string> M={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
    void helper(string digits, int k,string* partial_mnemonic, vector<string>* Mnemonics){
        if(k==digits.size()){
            Mnemonics->push_back(*partial_mnemonic);
        }
        else{
            for(char c: M[digits[k]]){
                (*partial_mnemonic)[k]=c;
                helper(digits,k+1,partial_mnemonic,Mnemonics);
            }
        }
    } 
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return {};
        }
        vector <string> Mnemonics;
        string partial_mnemonic(digits.size(),0);
        helper(digits,0,&partial_mnemonic,&Mnemonics);
        return Mnemonics;
    }
};