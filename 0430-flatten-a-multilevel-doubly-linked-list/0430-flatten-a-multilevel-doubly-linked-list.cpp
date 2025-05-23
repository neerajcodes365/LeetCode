/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
private:
Node * temp;
    void help(Node * nod){
        if(nod==NULL) return;
        temp->next=nod;
        nod->prev=temp;
        temp=temp->next;
        Node * next=nod->next;
        if(nod->child!=NULL){
            help(nod->child);
            nod->child=NULL;
        }
        help(next);
    }

public:
    Node* flatten(Node* head) {
        if(head==NULL) return head;
    Node * dummy=new Node(0);
    temp=dummy;
    
    help(head);
    Node * ans=dummy->next;
    ans->prev=NULL;
    return ans;
    }
};