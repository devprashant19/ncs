class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(),points.end(),[](auto const &a,auto const &b){
            return (a[0]*a[0]+a[1]*a[1])<(b[0]*b[0]+b[1]*b[1]);
        });
        return vector<vector<int>>(points.begin(),points.begin()+k);
    }
};
