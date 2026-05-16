/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
    ListNode* add(ListNode* l1,ListNode* l2,int carry){
        if(!l1 && !l2 && carry==0)return NULL;
        int v1=0,v2=0;
        if(l1)v1=l1->val;
        if(l2)v2=l2->val;
        int val=v1+v2+carry;
        int nodeVal=val%10;
        int newc=val/10;
        ListNode* nextNode=add(l1?l1->next:NULL,l2?l2->next:NULL,newc);
        return new ListNode(nodeVal,nextNode);
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1,l2,0);
    }
};
