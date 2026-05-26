class Solution {
    int f(int steps,vector<int>&dp){
        if(steps==0)return 1;
        if(steps<0)return 0;
        if(dp[steps]!=-1)return dp[steps];
        return dp[steps]=f(steps-1,dp)+f(steps-2,dp);
    }
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return f(n,dp);
    }
};