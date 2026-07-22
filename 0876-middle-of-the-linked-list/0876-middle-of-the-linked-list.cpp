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
    ListNode* middleNode(ListNode* head) {
    using node = ListNode;
    node* single=head;
    node* dou=head;
    while(dou!=nullptr&&dou->next!=nullptr){
        dou=dou->next->next;
        single=single->next;
    }
    return single;
    }
};