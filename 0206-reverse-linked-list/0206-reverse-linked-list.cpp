/**
 * Definition for singly-linked list.
 * struct node {
 *     int val;
 *     node *next;
 *     node() : val(0), next(nullptr) {}
 *     node(int x) : val(x), next(nullptr) {}
 *     node(int x, node *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp=head;
        ListNode * prv=nullptr;

        while(temp!=nullptr){
            ListNode*help=temp->next;
           temp->next=prv;
           prv=temp;
           temp=help;
        }
        return prv;


    }
};