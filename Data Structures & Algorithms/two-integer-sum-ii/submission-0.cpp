class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        int n=a.size();
        int l=0,r=n-1;
        while(l<r){
            if(a[l]+a[r]==target)return {l+1,r+1};
            else if(a[l]+a[r]<target)l++;
            else r--;
        }
    }
};
