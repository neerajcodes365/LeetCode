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
 if (head == NULL) return NULL;
Node * temp=head;
while(temp!=NULL){
    Node * dup=new Node(temp->val);
    // dup->val=temp->val;
    dup->random=temp->random;
  dup->next = temp->next;
            temp->next = dup;
            temp = dup->next;
}
 temp = head;
while (temp != NULL) {
    if (temp->random != NULL)
        temp->next->random = temp->random->next;
    temp = temp->next->next;
}

Node* dummy = head->next;
Node* copy = dummy;
temp = head;

while (temp != NULL) {
    temp->next = temp->next->next;  
    if (copy->next != NULL)
        copy->next = copy->next->next;  
    temp = temp->next;
    copy = copy->next;
}
return dummy;
    }
};