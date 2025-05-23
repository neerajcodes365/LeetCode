/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode *check(ListNode * slow2,ListNode * fast){
        while(slow2!=fast){
            slow2=slow2->next;
            fast=fast->next;
        }
        return slow2;
    }
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return NULL;
        struct ListNode * slow=head;
        struct ListNode * slow2=head;
        struct ListNode * fast=head;
        while(slow!=NULL && fast->next!=NULL ){
            slow=slow->next;
            fast=fast->next->next;
            if(slow == fast) {
                return check(slow2,fast);
            }

        }
        return NULL;
    }
};