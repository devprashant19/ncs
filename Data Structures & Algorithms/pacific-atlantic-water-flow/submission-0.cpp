class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<bool>>vis1(m,vector<bool>(n,false));
        vector<vector<bool>>vis2(m,vector<bool>(n,false));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            q.push({0,i});
            vis1[0][i]=true;
        }
        for(int i=1;i<m;i++){
            q.push({i,0});
            vis1[i][0]=true;
        }
        int dr[4]={0,1,0,-1};
        int dc[4]={-1,0,1,0};
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int dr1=r+dr[k];
                int dc1=c+dc[k];
                if(dr1>=0 && dc1>=0 && dr1<m && dc1<n && !vis1[dr1][dc1] && heights[dr1][dc1]>=heights[r][c]){
                    q.push({dr1,dc1});
                    vis1[dr1][dc1]=true;
                }
            }
        }
        for(int i=0;i<m;i++){
            q.push({i,n-1});
            vis2[i][n-1]=true;
        }
        for(int i=0;i<n-1;i++){
            q.push({m-1,i});
            vis2[m-1][i]=true;
        }
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int dr1=r+dr[k];
                int dc1=c+dc[k];
                if(dr1>=0 && dc1>=0 && dr1<m && dc1<n && !vis2[dr1][dc1] && heights[dr1][dc1]>=heights[r][c]){
                    q.push({dr1,dc1});
                    vis2[dr1][dc1]=true;
                }
            }
        }
        vector<vector<int>>res;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis1[i][j]&&vis2[i][j])res.push_back({i,j});
            }
            }
        return res;
    }
};