class Node{
    public:
        int key;
        int val;
        int freq;
        Node* prev;
        Node* next;
        Node(int k,int v){
            key=k;
            val=v;
            freq=1;
            prev=next=NULL;
        }
};
class List{
    public:
        int size; 
        Node* head;
        Node* tail;
        List(){
            head=new Node(0,0);
            tail=new Node(0,0);
            head->next=tail;
            tail->prev=head;
            size=0;
        }
        void removeNode(Node* node){
            node->prev->next=node->next;
            node->next->prev=node->prev;
            size--;
        }
        void addFront(Node* node){
            Node* temp=head->next;
            node->next=temp;
            node->prev=head;
            head->next=node;
            temp->prev=node;
            size++;
        }
};
class LFUCache {
    map<int,List*>freq;
    map<int,Node*>mpp;
    int minFreq,curSize,cap;
public:
    LFUCache(int capacity) {
        cap=capacity;
        minFreq=0;
        curSize=0;
    }
    void f(Node* node){
        int oldFreq = node->freq;
        List* oldList = freq[oldFreq];
        oldList->removeNode(node);
        if (oldFreq == minFreq && oldList->head->next == oldList->tail)minFreq++;
        node->freq += 1;
        List* nextList;
        if (freq.find(node->freq) != freq.end() && freq[node->freq] != nullptr) {
            nextList = freq[node->freq];
        } else {
            nextList = new List();
            freq[node->freq] = nextList;
        }
        nextList->addFront(node);
        mpp[node->key] = node;
    }
    int get(int key) {
        if(mpp.find(key)==mpp.end())return -1;
        Node* node=mpp[key];
        int val=node->val;
        f(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(cap==0)return;
        if(mpp.find(key)!=mpp.end()){
            Node* node=mpp[key];
            node->val=value;
            f(node);
        }else{
            if (mpp.size() >= cap) {
                List* minList = freq[minFreq];
                Node* nodeToDelete = minList->tail->prev;
                mpp.erase(nodeToDelete->key);
                minList->removeNode(nodeToDelete);
                delete nodeToDelete;
            }
            minFreq = 1;
            Node* newNode = new Node(key, value);
            List* listOne = new List();
            if (freq.find(1) != freq.end()) {
                listOne = freq[1];
            }
            listOne->addFront(newNode);
            freq[1] = listOne;
            mpp[key] = newNode;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */