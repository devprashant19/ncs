class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>mpp(26,0);
        vector<int>mpp2(26,0);
        for(char i:s1)mpp[i-'a']++;
        int l=0,r=0;
        while(r<s2.size()){
            mpp2[s2[r]-'a']++;
            while(r-l+1>s1.size()){
                mpp2[s2[l]-'a']--;
                l++;
            }
            if(mpp==mpp2)return true;
            r++;
        }
        return false;
    }
};
