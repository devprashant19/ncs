class Solution {
    private:
    int maxRob(int n,vector<int>&nums,vector<int> &dp){
        if(n<0)return 0;
        if(dp[n]!=-1)return dp[n];
        int t1=nums[n]+maxRob(n-2,nums,dp);
        int t2=maxRob(n-1,nums,dp);
        return dp[n]=max(t1,t2);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return maxRob(n-1,nums,dp);
    }
};