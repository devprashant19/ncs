class Node{
    public:
    int val;
    Node* next;
    Node(int x){
        this->val=x;
        this->next=NULL;
    }
};
class MyCircularQueue {
    Node* head;
    Node* tail;
public:
    MyCircularQueue(int k) {
        head=new Node(-1);
        Node* curr=head;
        for(int i=0;i<k-1;i++){
            Node* newNode=new Node(-1);
            curr->next=newNode;
            curr=newNode;
        }
        curr->next=head;
        tail=head;
    }
    
    bool enQueue(int value) {
        if(isFull())return false;
        if(isEmpty()){
            head->val=value;
            tail=head;
        }else{
            tail=tail->next;
            tail->val=value;
        }
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())return false;
        head->val=-1;
        head=head->next;
        return true;
    }
    
    int Front() {
        if(isEmpty())return -1;
        return head->val;
    }
    
    int Rear() {
        if(isEmpty())return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        return head->val==-1;
    }
    
    bool isFull() {
        return tail->next==head && head->val!=-1;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */