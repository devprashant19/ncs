class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int dr[4]={0,1,-1,0};
        int dc[4]={1,0,0,-1};
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)q.push({i,j});
            }
        }
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int dr1=r+dr[k];
                int dr2=c+dc[k];
                while(dr1>=0 && dr2>=0 && dr1<m && dr2<n && grid[dr1][dr2]==2147483647){
                    grid[dr1][dr2]=grid[r][c]+1;
                    q.push({dr1,dr2});
                }
            }
        }
    }
};
