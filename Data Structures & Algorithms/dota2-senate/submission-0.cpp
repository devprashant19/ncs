class Solution {
public:
    string predictPartyVictory(string s) {
        int n=s.size();
        queue<int>q1;
        queue<int>q2;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(s[i]=='R')q1.push(i);
            else q2.push(i);
        }
        while(!q1.empty() && !q2.empty()){
            int v1=q1.front();
            int v2=q2.front();
            q1.pop();
            q2.pop();
            if(v1<v2)q1.push(v1+n);
            else q2.push(v2+n);
        }
        return q2.empty()?"Radiant":"Dire";
    }
};