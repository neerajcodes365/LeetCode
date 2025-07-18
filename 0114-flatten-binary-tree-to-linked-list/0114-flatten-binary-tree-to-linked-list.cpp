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
    // typedef TreeNode node;
public:
    void help(TreeNode*root,queue<TreeNode*>&q){
        if(root==nullptr)return;
        q.push(root);
        help(root->left,q);
        help(root->right,q);
    }
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        queue<TreeNode*>q;
        help(root,q);
            TreeNode * a=q.front();
            q.pop();
        while(!q.empty()){
            a->left=nullptr;
            a->right=q.front();
            a=q.front();
            q.pop();
        }
a->left=nullptr;
    }
};

