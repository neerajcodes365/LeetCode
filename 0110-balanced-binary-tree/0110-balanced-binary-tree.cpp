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
int flag;
//     void help(TreeNode * root){
//         if(root==nullptr) 
//         int left=help(root->left);
//         int right=help(root->right);

//     }
    int help(TreeNode * root){
        if(root==nullptr) return 0;
        int left=help(root->left);
        int right=help(root->right);
        if(abs(left-right)>1)flag=1;
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        flag=0;
        // help(root);
        // if(root==nullptr)return ;
        int a=help(root);
        if(flag)return false;
        return true;


    }
};