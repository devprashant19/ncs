class NumMatrix {
    int r,c;
    vector<vector<int>>a;
public:
    NumMatrix(vector<vector<int>>& m) {
        r=m.size();
        c=r>0?m[0].size():0;
        a.resize(r+1,vector<int>(c+1,0));
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                a[i][j]=m[i-1][j-1]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        return a[row2+1][col2+1]-a[row2+1][col1]-a[row1][col2+1]+a[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */