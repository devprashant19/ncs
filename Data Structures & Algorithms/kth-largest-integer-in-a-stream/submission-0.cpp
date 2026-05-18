class KthLargest {
    int k1;
    vector<int>n;
public:
    KthLargest(int k, vector<int>& a) {
        for(int i=0;i<a.size();i++)n.push_back(a[i]);
        k1=k;
    }
    int add(int val) {
        n.push_back(val);
        sort(n.begin(),n.end());
        return n[n.size()-k1];    
    }
};
