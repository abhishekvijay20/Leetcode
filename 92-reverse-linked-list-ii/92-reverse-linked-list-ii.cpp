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
    ListNode* reverse(ListNode* head) {
        ListNode *p = NULL, *c = head, *n = head->next;
        while (c != NULL) {
            c->next = p;
            p = c;
            c = n;
            if (n != NULL) n = n->next;
        }
        return p;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *l1 = NULL, *l2 = NULL, *r1 = NULL, *r2 = NULL, *temp = head, *reversedHead = NULL;
        int pos = 1;
        while (temp != NULL) {
            if (pos == left-1) {
                l1 = temp;
            } 
            if (pos == left) {
                l2 = temp;
            }
            if (pos == right) {
                r1 = temp;
            }
            if (pos == right+1) {
                r2 = temp;
            }
            temp = temp->next;
            pos++;
        }
        if (r1 != NULL) r1->next = NULL;
        if (l2 != NULL) reversedHead = reverse(l2);
        // return reversedHead;
        if (l1 != NULL) l1->next = r1;
        if (l2 != NULL) l2->next = r2;
        if (left == 1) return reversedHead;
        return head;
    }
};