class Solution {
public:
    vector<int> topKFrequent(vector<int>& a, int k) {
        unordered_map<int,int>mpp;
        vector<int> res;
        int n=a.size();
        for(int i=0;i<n;i++){
            mpp[a[i]]++;
        }
        vector<pair<int,int>>vec(mpp.begin(),mpp.end());
        sort(vec.begin(),vec.end(),[](const auto &a,const auto &b){
            return a.second>b.second;
        });
        int v=0;
        while(k--){
            res.push_back(vec[v].first);
            v++;
        }
        return res;

    }
};
