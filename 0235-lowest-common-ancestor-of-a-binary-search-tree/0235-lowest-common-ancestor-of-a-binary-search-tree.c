/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



/*   BRUTE FORCE  

int max(int a, int b) {
    return a > b ? a : b;
}

int findlen(struct TreeNode* root, struct TreeNode* node) {
    struct TreeNode* temp = root;
    int count = 0;
    while (temp != NULL) {
        if (temp->val == node->val) return count + 1;
        count++;
        if (node->val > temp->val) {
            temp = temp->right;
        } else {
            temp = temp->left;
        }
    }
    return -1;
}

void insertarr(struct TreeNode* root, struct TreeNode* node, int* arr, int lenarr) {
    struct TreeNode* temp = root;
    int count = 0;
    while (temp != NULL) {
        arr[count] = temp->val;
        if (temp->val == node->val) break;
        count++;
        if (node->val > temp->val) {
            temp = temp->right;
        } else {
            temp = temp->left;
        }
    }
}

int find(int num, int* arr, int len) {
    for (int i = 0; i < len; i++) {
        if (arr[i] == num) return 1;
    }
    return 0;
}

struct TreeNode* findcheck(struct TreeNode* root, int* arr, struct TreeNode* node, int arrlen) {
    struct TreeNode* temp = root;
    struct TreeNode* final = NULL;
    while (temp != NULL) {
        if (find(temp->val, arr, arrlen)) {
            final = temp;
        }
        if (temp->val == node->val) {
            return final;
        }
        if (node->val > temp->val) {
            temp = temp->right;
        } else {
            temp = temp->left;
        }
    }
    return final;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    int lenp = findlen(root, p);
    int lenq = findlen(root, q);
    if (lenp == -1 || lenq == -1) return NULL;
    int* arr = (int*)malloc(sizeof(int) * max(lenp, lenq));
    if (lenp > lenq) {
        insertarr(root, p, arr, lenp);
        struct TreeNode* result = findcheck(root, arr, q, lenp);
        free(arr);
        return result;
    } else {
        insertarr(root, q, arr, lenq);
        struct TreeNode* result = findcheck(root, arr, p, lenq);
        free(arr);
        return result;
    }
}

*/

//optimized one 
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    while (root != NULL) {
        if (p->val < root->val && q->val < root->val) {
            root = root->left;
        }
        else if (p->val > root->val && q->val > root->val) {
            root = root->right;
        }
        else {
            return root;
        }
    }
    return NULL;  
}
