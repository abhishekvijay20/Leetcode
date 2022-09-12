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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> address;
        ListNode* temp = head;
        while (temp) {
            if (address.find(temp) != address.end()) {
                return temp;
            }
            address.insert(temp);
            temp = temp->next;
        }
        return NULL;
    }
};