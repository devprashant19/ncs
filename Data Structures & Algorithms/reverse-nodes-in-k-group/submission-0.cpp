class Solution{
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr=head;
        int m=0;
        while(curr!=NULL && m<k){
            curr=curr->next;
            m++;
        }
        if(m==k){
            curr=reverseKGroup(curr,k);
            while(m-->0){
                ListNode* temp=head->next;
                head->next=curr;
                curr=head;
                head=temp;
            }
            head=curr;
        }
        return head;
    }
};
