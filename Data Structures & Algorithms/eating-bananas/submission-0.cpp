class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int r=INT_MIN,l=1;
        int n=piles.size(),res=r;
        for(int i=0;i<n;i++)r=max(r,piles[i]);
        while(l<=r){
            int mid=l+(r-l)/2;
            int t=0;
            for(int i=0;i<n;i++){
                t+=ceil((double)piles[i]/mid);
            }
            if(t<=h){
                res=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return res;
    }
};
