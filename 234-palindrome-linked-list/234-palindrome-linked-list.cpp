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
    ListNode* reverse(ListNode* node) {
        if (node == NULL || node->next == NULL) return node;
        ListNode* prev = NULL, *curr = node, *nxt = curr->next;
        while (curr) {
            curr->next = prev;
            prev = curr;
            curr = nxt;
            if (nxt) nxt = nxt->next;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode *temp = new ListNode();
        temp->next = head;
        ListNode* slow = temp, *fast = temp;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow->next = reverse(slow->next);
        
        ListNode* p1 = head, *p2 = slow->next;
        while (p2) {
            if (p1->val != p2->val) return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
};