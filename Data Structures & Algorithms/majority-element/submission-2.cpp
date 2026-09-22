class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=1,val=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]!=val)cnt--;
            else cnt++;
            if(cnt<0){
                val=nums[i];
                cnt=1;
            }
        }
        return val;
    }
};