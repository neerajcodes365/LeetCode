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
    int ans=0;
    int help(TreeNode* root){
        if(root==nullptr) return 0;
        int a=help(root->left);
        int b=help(root->right);
        int maxi=max(a,b);
        if(root->val>=maxi){
            ans++;
            return root->val;
        }
        return maxi;
    }
    int countDominantNodes(TreeNode* root) {
        help(root);
        return ans;
        }
};