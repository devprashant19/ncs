class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr=head;
        while(curr->next){
            ListNode* n=curr->next;
            curr->next=new ListNode(__gcd(curr->val,n->val));
            curr->next->next=n;
            curr=n;
        }
        return head;
    }
};