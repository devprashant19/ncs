class Solution {
public:
    void solve(vector<vector<char>>& a) {
        int m=a.size();
        int n=a[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            if(a[0][i]=='O')q.push({0,i});
            if(a[m-1][i]=='O')q.push({m-1,i});
        }
        for(int i=1;i<m-1;i++){
            if(a[i][0]=='O')q.push({i,0});
            if(a[i][n-1]=='O')q.push({i,n-1});
        }
        int dr[4]={0,1,-1,0};
        int dc[4]={1,0,0,-1};
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            vis[r][c]=1;
            for(int k=0;k<4;k++){
                int dr1=r+dr[k];
                int dc1=c+dc[k];
                if(dr1>=0 && dr1<m && dc1>=0 && dc1<n && !vis[dr1][dc1] && a[dr1][dc1]=='O'){
                    vis[dr1][dc1]=1;
                    q.push({dr1,dc1});
                }
            }
        }   
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && a[i][j]=='O')a[i][j]='X';
            }
        }
    }
};
