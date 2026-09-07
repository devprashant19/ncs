class FreqStack {
    unordered_map<int,int>freq;
    unordered_map<int,stack<int>>m;
    int mFreq=0;
public:
    FreqStack() {
        
    }
    void push(int x) {
        freq[x]++;
        mFreq=max(mFreq,freq[x]);
        m[freq[x]].push(x);
    }
    int pop() {
        int x=m[mFreq].top();
        m[mFreq].pop();
        if(!m[freq[x]--].size())mFreq--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */