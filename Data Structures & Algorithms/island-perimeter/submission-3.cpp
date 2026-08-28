class Solution {
public:
 int count(vector<vector<int>>& g, int i, int j) {
        int s = 4;
        int n = g.size();
        int m = g[0].size();
        if (i > 0 && g[i-1][j] == 1)s--;
        if (i < n-1 && g[i+1][j] == 1)s--;
        if (j > 0 && g[i][j-1] == 1)s--;
        if (j < m-1 && g[i][j+1] == 1)s--;
        return s;
    }
    int islandPerimeter(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        int p = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 1) {
                    p += count(g, i, j);
                }
            }
        }
        return p;
    
    }
};