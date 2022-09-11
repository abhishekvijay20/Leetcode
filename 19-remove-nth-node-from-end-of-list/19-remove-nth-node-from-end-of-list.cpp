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
        ListNode* start = new ListNode();
        start->next = head;
        ListNode *fast = start, *slow = start;
        int i = 0;
        while (i < n) {
            fast = fast->next;
            i++;
        }
        
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode *del = slow->next;
        slow->next = del->next;
        delete del;
        return start->next;
    }
};