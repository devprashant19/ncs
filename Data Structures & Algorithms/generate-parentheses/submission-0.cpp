class Solution {
    vector<string> res;
    void f(string s,int n1,int n2,int n){
        if(s.length()==2*n){
            res.push_back(s);
            return;
        }
        if(n1<n)f(s+'(',n1+1,n2,n);
        if(n2<n1)f(s+')',n1,n2+1,n);
    }
public:
    vector<string> generateParenthesis(int n) {
        f("",0,0,n);
        return res;
    }
};
