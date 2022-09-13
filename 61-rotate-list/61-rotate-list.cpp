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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return head;
        ListNode* temp = head, *tail;
        int cnt = 0;
        while (temp) {
            if (temp->next == NULL) tail = temp;
            cnt++;
            temp = temp->next;
        }
        k = k % cnt;
        if (k == 0) return head;
        temp = head;
        int i = 1;
        while (i < cnt - k) {
            i++;
            temp = temp->next;
        }
        tail->next = head;
        ListNode* ans = temp->next;
        temp->next = NULL;
        return ans;
    }
};