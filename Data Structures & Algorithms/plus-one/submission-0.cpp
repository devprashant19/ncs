class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c=1,n=digits.size();
        for(int i=n-1;i>=0;i--){
            digits[i]+=c;
            c=digits[i]/10;
            digits[i]%=10;
        }
        if(c==1)digits.insert(digits.begin(),c);
        return digits;
    }
};
