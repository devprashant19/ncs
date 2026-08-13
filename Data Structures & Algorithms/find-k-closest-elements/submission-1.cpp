class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int val) {
        int x=val;
        sort(arr.begin(),arr.end(),[&](int &a,int &b){
            if(abs(x-a)==abs(x-b))return a<b;
            return abs(x-a)<abs(x-b);
        });
        vector<int>ans(arr.begin(),arr.begin()+k);
        sort(ans.begin(),ans.end());
        return ans;
    }
};