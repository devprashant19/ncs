class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr=0,maxSum=0;
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            if(curr<0)curr=0;
            maxSum=max(maxSum,curr);
        }
        if(maxSum==0){
            curr=INT_MIN;
            for(int i=0;i<nums.size();i++){
                if(nums[i]==0)return 0;
                else if(nums[i]<0)curr=max(curr,nums[i]);
            }
            return curr;
        }
        return maxSum;
    }
};
