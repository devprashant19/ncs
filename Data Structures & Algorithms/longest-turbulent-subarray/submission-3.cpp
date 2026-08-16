class Solution {
public:
    int maxTurbulenceSize(vector<int>& nums) {
        int cnt=1,maxVal=1;
        int n=nums.size();
        if(n==1)return 1;
        bool flag=false;
        for(int i=1;i<n;i++){
            if((flag && nums[i]<nums[i-1])||(!flag && nums[i]>nums[i-1])){
                flag=!flag;
                cnt++;
            }else{
                if(nums[i]<nums[i-1]){
                    flag=false;
                    cnt=2;
                }else if(nums[i]>nums[i-1]){
                    cnt=2;
                    flag=true;
                }else cnt=1;
            }
            maxVal=max(maxVal,cnt);
        }
        return maxVal;
    }
};