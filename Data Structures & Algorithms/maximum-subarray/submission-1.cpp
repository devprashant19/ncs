class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr=0,maxSum=nums[0];
        for(int i=0;i<nums.size();i++){
            if(curr<0)curr=0;
            curr+=nums[i];
            maxSum=max(maxSum,curr);
        }
        return maxSum;
    }
};
