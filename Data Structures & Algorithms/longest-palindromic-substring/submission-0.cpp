class Solution {
    int x=0,maxl=1;
    void f(int l,int r,string &s,int n){
        while(l>=0 && r<n && s[l]==s[r]){
            int curr=r-l+1;
            if(curr>maxl){
                x=l;
                maxl=curr;
            }
            l--;
            r++;
        }
    }
public:
    string longestPalindrome(string s) {
        int n=s.size();
        for(int i=0;i<n;i++){
            f(i,i,s,n);
            f(i,i+1,s,n);
        }
        return s.substr(x,maxl);
    }
};