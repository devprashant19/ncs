class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<string>a(strs.begin(),strs.end());
        vector<bool>flag(n,false);
        vector<vector<string>>ans;
        for(int i=0;i<n;i++)sort(a[i].begin(),a[i].end());
        for(int i=0;i<n;i++){
            if(flag[i])continue;
            string val=a[i];
            ans.push_back({strs[i]});
            for(int j=i+1;j<n;j++){
                if(a[i]==a[j]){
                    flag[j]=true;
                    ans[ans.size()-1].push_back(strs[j]);
                }
            }
        }
        return ans;
    }
};
