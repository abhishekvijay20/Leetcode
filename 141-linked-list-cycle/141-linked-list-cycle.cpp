/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*> address;
        ListNode* temp = head;
        while (temp) {
            if (address.find(temp) != address.end()) return true;
            address.insert(temp);
            temp = temp->next;
        }
        return false;
    }
};