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
        using node=ListNode;
        node* dummy =new node(0);
        node* t=dummy;
        int carry=0;
        node* t1=l1;
        node * t2=l2;
        
        while(t1!=nullptr && t2!=nullptr){
            int num=t1->val+t2->val+carry;
            carry=num>=10?1:0;
            num=num%10;
            t->next=new node(num);
            t1=t1->next;
            t2=t2->next;
            t=t->next;

        }
        while(t1!=nullptr){
            int num=t1->val+carry;
            carry=num>=10?1:0;
            num=num%10;
            t->next=new node(num);
            t1=t1->next;
            t=t->next;

        }
        while(t2!=nullptr){
            int num=t2->val+carry;
            carry=num>=10?1:0;
            num=num%10;
            t->next=new node(num);
            t2=t2->next;
            t=t->next;

        }
        if(carry==1) t->next=new node(1);
        return dummy->next;
    }
};