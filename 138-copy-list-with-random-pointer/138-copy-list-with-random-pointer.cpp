/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m;
        m[NULL] = NULL;
        Node* temp = head;
        Node* newHead = NULL, *newTail = NULL;
        while (temp) {
            if (newHead == NULL) {
                newHead = new Node(temp->val);
                newTail = newHead;
            } else {
                newTail->next = new Node(temp->val);
                newTail = newTail->next;
            }
            m[temp] = newTail;
            temp = temp->next;
        }
        
        temp = head;
        while (temp) {
            m[temp]->random = m[temp->random];
            temp = temp->next;
        }
        
        return newHead;
    }
};