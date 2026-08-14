class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left==right)return head;
        ListNode* dNode=new ListNode(0);
        dNode->next=head;
        ListNode* prev=dNode;
        for(int i=0;i<left-1;i++)prev=prev->next;
        ListNode* curr=prev->next;
        for(int i=0;i<right-left;i++){
            ListNode* node=curr->next;
            curr->next=node->next;
            node->next=prev->next;
            prev->next=node;
        }
        ListNode* nHead=dNode->next;
        delete dNode;
        return nHead;
    }
};