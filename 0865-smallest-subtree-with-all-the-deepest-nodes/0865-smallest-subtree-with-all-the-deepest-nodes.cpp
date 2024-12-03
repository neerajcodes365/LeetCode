/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* res = nullptr;
    int deepestLevel = 0;

    int dfs(TreeNode* root, int height) {
        if (!root) return height;
        int leftHeight = dfs(root->left, height + 1);
        int rightHeight = dfs(root->right, height + 1);
        int currLevel= max(leftHeight, rightHeight);
        if(currLevel>=deepestLevel){
            deepestLevel=currLevel;
            if(leftHeight==deepestLevel && rightHeight==deepestLevel){
                res=root;
            }
            
        }
        
        return max(leftHeight, rightHeight);
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
};
/*/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 
int maax(int a, int b) {
    return a > b ? a : b;
}

int help(struct TreeNode* root, struct TreeNode** temp, int level, int* maxlevel) {
    if (root == NULL) return level;

    // Get the depth of the left and right subtrees
    int left = help(root->left, temp, level + 1, maxlevel);
    int right = help(root->right, temp, level + 1, maxlevel);

    // Update the result if left and right subtrees are balanced and level is deeper
    if (left == right && level > *maxlevel) {
        *temp = root;
        *maxlevel = level;
    }

    // Return the maximum depth of the two subtrees
    return maax(left, right);
}

struct TreeNode* subtreeWithAllDeepest(struct TreeNode* root) {
    int maxlevel = -1;
    struct TreeNode* temp = NULL;
    help(root, &temp, 0, &maxlevel);
    return temp;
}
 */