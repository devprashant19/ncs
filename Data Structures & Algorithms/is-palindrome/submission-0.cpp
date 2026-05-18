class Solution {
public:
    bool isPalindrome(string s) {
        string nStr="";
        for(char i:s){
            if(isalnum(i))nStr+=tolower(i);
        }
        int l=0,r=nStr.size()-1;
        cout<<nStr;
        while(l<r){
            if(nStr[l]!=nStr[r])return false;
            l++;
            r--;
        }
        return true;
    }
};
