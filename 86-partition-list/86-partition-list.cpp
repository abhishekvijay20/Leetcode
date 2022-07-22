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
    ListNode* partition(ListNode* head, int x) {
        ListNode* left = new ListNode(0);
        ListNode* leftHead = left;
        ListNode* right = new ListNode(0);
        ListNode* rightHead = right;
        ListNode* temp = head;
        while (temp != NULL) {
            ListNode *newNode = new ListNode(temp->val);
            if (temp->val < x) {
                left->next = newNode;
                left = left->next;
            } else {
                right->next = newNode;
                right = right->next;
            }
            temp = temp->next;
        }
        left->next = rightHead->next;
        right->next = NULL;
        return leftHead->next;
    }
};