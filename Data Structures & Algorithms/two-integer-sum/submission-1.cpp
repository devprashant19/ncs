class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>q;
        vector<int> ans;
        for(int i = 0;i < nums.size();i++){
            if(q.find(target - nums[i]) != q.end()){
                ans.push_back(q[target - nums[i]]);
                ans.push_back(i);
            }else{
                q.insert({nums[i],i});
            }
        }
        return ans;
    }
};
