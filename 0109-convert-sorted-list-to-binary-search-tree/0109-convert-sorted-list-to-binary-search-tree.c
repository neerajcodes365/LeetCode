int findLength(struct ListNode* head) {
    int length = 0;
    struct ListNode* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

int findMiddleIndex(int start, int end) {
    return (start + end) / 2;
}

struct TreeNode* createTreeNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* buildTree(int* arr, int start, int end) {
    if (start > end) return NULL;
    int mid = findMiddleIndex(start, end);
    struct TreeNode* root = createTreeNode(arr[mid]);
    root->left = buildTree(arr, start, mid - 1);
    root->right = buildTree(arr, mid + 1, end);
    return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    if (head == NULL) return NULL;
    int len = findLength(head);
    int* arr = (int*)malloc(sizeof(int) * len);
    struct ListNode* temp = head;
    for (int i = 0; i < len; i++) {
        arr[i] = temp->val;
        temp = temp->next;
    }
    struct TreeNode* root = buildTree(arr, 0, len - 1);
    return root;
}
