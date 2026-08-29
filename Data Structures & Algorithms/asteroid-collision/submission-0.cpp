class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int>st;
        int n=a.size();
        for(int i=0;i<n;i++){
            if(a[i]>0)st.push(a[i]);
            else{
                while(!st.empty() && st.top()>0 && st.top()<-a[i])st.pop();
                if(!st.empty() && st.top()==-a[i]){
                    st.pop();
                    continue;
                }
                else if(st.empty() || st.top()<0)st.push(a[i]);
            }
        }
        int s=st.size();
        vector<int>ans(s);
        for(int i=s-1;i>=0;i--){
            ans[i]=st.top();
            st.pop();
        }
        return ans;
    }
};