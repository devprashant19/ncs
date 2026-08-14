class Solution {
public:
    bool f(string &s,int left,int right) {
        while(left<right) {
            if(s[left++]!=s[right--])return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int left=0,right=s.size()-1;
        while(left<right){
            if (s[left]!=s[right]) {
                return f(s,left+1,right)||f(s,left,right-1);
            }
            left++;
            right--;
        }
        return true;
    }
};