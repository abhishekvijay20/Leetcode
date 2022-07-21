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
private:
    pair<ListNode*, ListNode*> helper (ListNode* head, ListNode* tail) {
        if (head == tail) return {head, tail};
        
        pair<ListNode*, ListNode*> smallAns = helper(head->next, tail);
        smallAns.second->next = head;
        head->next = NULL;
        smallAns.second = smallAns.second->next;
        return smallAns;
    }
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return head;
        ListNode* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        pair<ListNode*, ListNode*> ans = helper (head, temp);
        return ans.first;
    }
};