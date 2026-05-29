class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mpp;
        int l=0,r=0,maxVal=0;
        int n=s.size();
        while(r<s.size()){
            mpp[s[r]]++;
            while(mpp[s[r]]>1){
                mpp[s[l]]--;
                l++;
            }
            maxVal=max(maxVal,r-l+1);
            r++;
        }
        return maxVal;
    }
};
