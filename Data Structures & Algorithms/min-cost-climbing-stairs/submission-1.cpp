class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+2,0);
        for(int i=n-1;i>=0;i--){
            int v1=cost[i]+dp[i+1];
            int v2=cost[i]+dp[i+2];
            dp[i]=min(v1,v2);
        }
        return min(dp[0],dp[1]);
    }
};
