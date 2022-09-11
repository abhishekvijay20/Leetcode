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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1, *temp2 = l2, *ansHead = NULL, *ansTail = NULL;
        int carry = 0;
        while (temp1 && temp2) {
            int sum = temp1->val + temp2->val + carry;
            int nodeVal = sum % 10;
            carry = sum / 10;
            if (ansHead == NULL) {
                ansHead = new ListNode(nodeVal);
                ansTail = ansHead;
            } else {
                ansTail->next = new ListNode(nodeVal);
                ansTail = ansTail->next;
            }
            
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        while (temp1) {
            int sum = temp1->val + carry;
            int nodeVal = sum % 10;
            carry = sum / 10;
            if (ansHead == NULL) {
                ansHead = new ListNode(nodeVal);
                ansTail = ansHead;
            } else {
                ansTail->next = new ListNode(nodeVal);
                ansTail = ansTail->next;
            }            
            temp1 = temp1->next;           
        }
        
        while (temp2) {
            int sum = temp2->val + carry;
            int nodeVal = sum % 10;
            carry = sum / 10;
            if (ansHead == NULL) {
                ansHead = new ListNode(nodeVal);
                ansTail = ansHead;
            } else {
                ansTail->next = new ListNode(nodeVal);
                ansTail = ansTail->next;
            }
            temp2 = temp2->next;            
        }
        
        if (carry > 0) {
            ansTail->next = new ListNode(carry);
        }
        
        return ansHead;
    }
};