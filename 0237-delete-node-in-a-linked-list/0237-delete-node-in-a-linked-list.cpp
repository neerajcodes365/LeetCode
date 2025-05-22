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
    void deleteNode(ListNode* temp) {
        // struct ListNode * temp=node;
        temp->val=temp->next->val;
       // struct ListNode * tempfree=temp->next;
        temp->next=temp->next->next;
        // free(tempfree);
        //delete tempfree;
        }
};