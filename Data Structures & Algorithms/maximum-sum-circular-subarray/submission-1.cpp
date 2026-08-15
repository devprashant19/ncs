class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size(),maxSum=nums[0];
        for(int i=0;i<2*n;i++){
            int sum=0;
            for(int j=i;j<i+n;j++){
                sum+=nums[j%n];
                maxSum=max(maxSum,sum);
            }
        }
        return maxSum;
    }
};