class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        int l=0,r=m-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(target>matrix[mid][n-1])l=mid+1;
            else if(target<matrix[mid][0])r=mid-1;
            else break;
        }
        if(l>r)return false;
        int mid=l+(r-l)/2;
        l=0,r=n-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(target>matrix[mid][m])l=m+1;
            else if(target<matrix[mid][m])r=m-1;
            else return true;
        }
        return false;
    }
};