class Node{
    public:
        int val;
        Node* next;
        Node(int x){
            val=x;
            next=NULL;
        }
};
class MinStack {
    stack<int>st;
    Node* minNode;
public:
    MinStack() {
        minNode=new Node(INT_MAX);
    }
    
    void push(int value) {
        st.push(value);
        if(value<=minNode->val){
            Node* newNode=new Node(value);
            newNode->next=minNode;
            minNode=newNode;
        }
    }
    
    void pop() {
        if(st.top()==minNode->val){
            Node*temp=minNode;
            minNode=minNode->next;
            delete temp;
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minNode->val;
    }
};
