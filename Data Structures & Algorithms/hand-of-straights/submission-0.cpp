class Solution {
public:
    bool isNStraightHand(vector<int>& a, int k) {
        int n=a.size();
        if(n%k!=0)return false;
        map<int,int>mpp;
        for(int x:a)mpp[x]++;
        int cnt=0;
        for(int i=0;i<n/k;i++){
            auto val=mpp.begin();
            val->second--;
            int c=val->first;
            if(val->second==0)mpp.erase(val->first);
            for(int j=1;j<k;j++){
                if(mpp.find(++c)!=mpp.end()){
                    mpp[c]--;
                    if(mpp[c]==0)mpp.erase(c);
                }else return false;
            }
        }
        return true;
    }
};