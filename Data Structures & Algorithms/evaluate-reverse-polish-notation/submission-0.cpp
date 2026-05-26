class Solution {
public:
    int evalRPN(vector<string>& s) {
        stack<int>st;
        int l=0;
        while(l<s.size()){
            if(s[l]=="+"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(a+b);
            }else if(s[l]=="-"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(b-a);
            }
            else if(s[l]=="*"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(a*b);
            }
            else if(s[l]=="/"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(b/a);
            }else st.push(stoi(s[l]));
            l++;
        }
        return st.top();
    }
};
