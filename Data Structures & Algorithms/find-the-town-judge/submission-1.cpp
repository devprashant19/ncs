class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>a(n+1,0);
        for(int i=0;i<trust.size();i++){
            a[trust[i][0]]--;
            a[trust[i][1]]++;
        }
        for(int i=1;i<=n;i++){
            if(a[i]==n-1)return i;
        }
        return -1;
    }
};