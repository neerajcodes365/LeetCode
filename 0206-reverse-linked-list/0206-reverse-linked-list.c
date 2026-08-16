/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* had) {
    struct ListNode* prv=NULL;
    struct ListNode* tmp=had;
    while(tmp!=NULL){
        struct ListNode* nxtt=tmp->next;
        tmp->next=prv;
        prv=tmp;
        tmp=nxtt;
    }
    return prv;
}