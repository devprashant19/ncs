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
public:
    bool hasCycle(ListNode* head) {
        unordered_map<ListNode*,bool>mpp;
        ListNode* curr=head;
        while(curr!=NULL){
            if(mpp[curr])return true;
            mpp[curr]=true;
            curr=curr->next;
        }
        return false;
    }
};
