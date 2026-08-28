class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int>hash(26,0);
        int n=order.size();
        int m=words.size();
        for(int i=0;i<n;i++)hash[order[i]-'a']=i;
        for(int k=0;k<m-1;k++){
            string s1=words[k];
            string s2=words[k+1];
            int i=0,j=0;
            bool flag=false;
            while(i<s1.size() && j<s2.size()){
                if(hash[s1[i]-'a']>hash[s2[i]-'a'])return false;
                if(hash[s1[i]-'a']<hash[s2[i]-'a']){
                    flag=true;
                    break;
                }
                i++;
                j++;
            }
            if(!flag && s1.size()>s2.size())return false;
        }
        return true;
    }
};