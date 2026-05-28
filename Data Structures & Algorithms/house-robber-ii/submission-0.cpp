class Solution {
    vector<vector<int>>dp;
    int f(int i,int flag,vector<int>&nums){
        if(i>=nums.size()||(flag==1 && i==nums.size()-1))return 0;
        if(dp[i][flag]!=-1)return dp[i][flag];
        return dp[i][flag]=max(f(i+1,flag,nums),nums[i]+f(i+2,flag|(i==0?1:0),nums));
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        dp.resize(n,vector<int>(2,-1));
        return max(f(0,1,nums),f(1,0,nums));
    }
};
