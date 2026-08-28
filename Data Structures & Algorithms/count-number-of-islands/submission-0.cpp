class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        queue<pair<int,int>>q;
        int dr[4]={1,0,-1,0};
        int dc[4]={0,1,0,-1};
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    q.push({i,j});
                    while(!q.empty()){
                        auto [r,c]=q.front();
                        q.pop();
                        vis[r][c]=1;
                        for(int k=0;k<4;k++){
                            int dr1=r+dr[k];
                            int dr2=c+dc[k];
                            if(dr1>=0 && dr2>=0 && dr1<m && dr2<n && grid[dr1][dr2]=='1' && !vis[dr1][dr2]){
                                q.push({dr1,dr2});
                                vis[dr1][dr2]=1;
                            }
                        }         
                    }
                }
            }
        }
        return cnt;
    }
};
