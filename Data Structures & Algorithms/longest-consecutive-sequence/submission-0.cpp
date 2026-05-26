class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        int longest=0;
        for(int it:s){
            if(s.find(it-1)==s.end()){
                int len=1;
                while(s.find(it+len)!=s.end())len++;
                longest=max(longest,len);
            }
        }
        return longest;
    }
};
