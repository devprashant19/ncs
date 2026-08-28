class Solution {
public:
    int candy(vector<int>& a) {
        int n=a.size();
        vector<int> left(n,1);
        vector<int> right(n,1);
        int ans=0;
        for(int i=0;i<n;i++){
            if(i>0 && a[i]>a[i-1])left[i]=left[i-1]+1;
            if(i<n-1 && a[n-i-2]>a[n-i-1])right[n-i-2]=right[n-i-1]+1;
        }
        for(int i=0;i<n;i++)ans+=max(left[i],right[i]);
        return ans;
    }
};