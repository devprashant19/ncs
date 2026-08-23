class Solution {
public:
    int canCompleteCircuit(vector<int>& g, vector<int>& c) {
        int n=g.size();
        int posVal=0,idx=0,val=0;
        for(int i=0;i<n;i++){
            val+=g[i]-c[i];
            posVal+=g[i]-c[i];
            if(posVal<0){
                posVal=0;
                idx=i+1;
            }
        }
        return (val<0)?-1:idx%n;
    }
};