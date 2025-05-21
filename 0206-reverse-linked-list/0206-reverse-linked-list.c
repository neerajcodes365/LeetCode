/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
       struct ListNode* prev = NULL;
    struct ListNode* current = head;
    struct ListNode* next = NULL;

    while (current != NULL) {
        next = current->next;  // Store the next node
        current->next = prev;  // Reverse the current node's pointer
        prev = current;        // Move prev one step forward
        current = next;        // Move current one step forward
    }

    head = prev;  // Update the head to the new front of the list
    return head;

    
}