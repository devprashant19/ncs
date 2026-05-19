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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy=new ListNode(-1);
        dummy->next = head;
        int count = 0;
        auto dfs = [&](auto& self, ListNode* curr) -> void {
            if (curr == nullptr) return;
            self(self, curr->next);
            count++;
            if (count == n + 1) {
                ListNode* toDelete = curr->next;
                curr->next = curr->next->next;
                delete toDelete;
            }
        };
        dfs(dfs,dummy);
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
