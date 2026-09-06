class Solution {
public:
    int carFleet(int target, vector<int>&position, vector<int>&speed) {
        int n=position.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)v.push_back({position[i],speed[i]});
        sort(v.rbegin(),v.rend());
        int cnt=1;
        double val=(double)(target-v[0].first)/v[0].second;
        for(int i=1;i<n;i++){
            double v2=(double)(target-v[i].first)/v[i].second;
            if(v2>val){
                cnt++;
                val=v2;
            }
        }
        return cnt;
    }
};
