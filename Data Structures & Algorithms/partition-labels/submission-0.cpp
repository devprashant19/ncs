class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        unordered_map<char,int>mpp;
        for(int i=0;i<n;i++)mpp[s[i]]=i;
        vector<int>ans;
        int l=0,r=0;
        while(l<n){
            int i=l;
            r=mpp[s[i]];
            while(i<r && r<n){
                if(mpp[s[i]]>r)r=mpp[s[i]];
                i++;
            }
            ans.push_back(r-l+1);
            l=r+1;
            r=l;
        }
        return ans;
    }
};
