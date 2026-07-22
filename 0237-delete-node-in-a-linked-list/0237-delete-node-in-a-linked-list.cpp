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
    void deleteNode(ListNode* node) {
        ListNode* prv=node;
        while(node->next!=nullptr){
        node->val=node->next->val;
        prv=node;
        node=node->next;
        
    }
    prv->next=nullptr;
    }
};