class Solution {
    int f(int step,vector<int>& cost,vector<int>&dp){
        if(step>=cost.size())return 0;
        if(dp[step]!=-1)return dp[step];
        int v1=cost[step]+f(step+1,cost,dp);
        int v2=cost[step]+f(step+2,cost,dp);
        return dp[step]=min(v1,v2);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,-1);
        return min(f(0,cost,dp),f(1,cost,dp));
    }
};
