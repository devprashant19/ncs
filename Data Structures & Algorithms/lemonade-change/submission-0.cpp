class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int a=0,b=0,n=bills.size();
        for(int i=0;i<n;i++){
            if(bills[i]==5)a++;
            else if(bills[i]==10){
                if(a==0)return false;
                a--;
                b++;
            }
            else if(bills[i]==20){
                if(b==0){
                    if(a<3)return false;
                    a-=3;
                }else{
                    b--;
                    if(a==0)return false;
                    a--;
                }
            }
        }
        return true;
    }
};