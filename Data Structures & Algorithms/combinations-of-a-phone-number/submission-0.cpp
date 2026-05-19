class Solution {
    void f(string digits,int i,string ans,vector<string>&res,unordered_map<char,string> &mpp){
        if(i==digits.size()){
            res.push_back(ans);
            return;
        }
        string l=mpp.at(digits[i]);
        for(char y:l){
            f(digits,i+1,ans+y,res,mpp);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>mpp;
        vector<string>res;
        if(digits.empty())return res;
        mpp['2']="abc";
        mpp['3']="def";
        mpp['4']="ghi";
        mpp['5']="jkl";
        mpp['6']="mno";
        mpp['7']="pqrs";
        mpp['8']="tuv";
        mpp['9']="wxyz";
        f(digits,0,"",res,mpp);
        return res;
    }
};