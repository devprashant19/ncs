class Solution {
public:
    string decodeString(string s) {
        int n=s.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i]!=']')st.push(s[i]);
            else{
                string res="";
                while(st.top()!='['){
                    res=st.top()+res;
                    st.pop();
                }
                st.pop();
                int val=0,i=1;
                while(!st.empty() && isdigit(st.top())){
                    val=val+(st.top()-'0')*i;
                    i*=10;
                    st.pop();
                }
                for(int i=0;i<val;i++){
                    for(int j=0;j<res.size();j++){
                        st.push(res[j]);
                    }
                }
            }
        }
        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};