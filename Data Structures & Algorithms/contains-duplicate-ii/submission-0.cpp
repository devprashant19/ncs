class Solution {
public:
    bool containsNearbyDuplicate(vector<int>&a, int k) {
        int n=a.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            if(mpp.find(a[i])!=mpp.end()){
                if(abs(i-mpp[a[i]])<=k)return true;
            }
            mpp[a[i]]=i;
        }
        return false;
    }
};