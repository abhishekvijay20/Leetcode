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
    ListNode* collidePoint(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return slow;
        }
        return NULL;        
    }
    
    ListNode *detectCycle(ListNode *head) {
        ListNode* point = collidePoint(head), *entry = head;
        if (point == NULL) return NULL;
        
        while (entry != point) {
            entry = entry->next;
            point = point->next;
        }
        return point;
    }
};