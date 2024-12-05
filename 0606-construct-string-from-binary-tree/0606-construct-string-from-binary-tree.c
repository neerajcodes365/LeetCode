/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//Constraints:
// The number of nodes in the tree is in the range [1, 104].
// -1000 <= Node.val <= 1000
void help(struct TreeNode *root, int *i, char *string) {
    if (root == NULL) return;

    *i += sprintf(&string[*i], "%d", root->val);

    if (root->left || root->right) {
        string[(*i)++] = '(';
        help(root->left, i, string);
        string[(*i)++] = ')';
    }

    if (root->right) {
        string[(*i)++] = '(';
        help(root->right, i, string);
        string[(*i)++] = ')';
    }
}

char* tree2str(struct TreeNode* root) {
    char *string = (char *)calloc(100000, sizeof(char));
    int i = 0;
    help(root, &i, string);
    return string;
}
