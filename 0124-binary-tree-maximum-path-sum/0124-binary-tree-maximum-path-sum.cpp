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
    int maxi;
    int help(TreeNode* root){
        if(root==nullptr)return 0;
        int nodeval=root->val;
        int left=max(0,help(root->left));
        int right=max(0,help(root->right));
        maxi=max(nodeval+left+right,maxi);
        return max({nodeval,nodeval+right,nodeval+left});
    }
    int maxPathSum(TreeNode* root) {
        if(root==nullptr)return 0;
         maxi=INT_MIN;
        int a=help(root);
        return maxi;
    }
};