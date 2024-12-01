/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if(root==NULL)return NULL;
  
    struct TreeNode * left=lowestCommonAncestor(root->left,p,q);
    struct TreeNode * right=lowestCommonAncestor(root->right,p,q);

    // if(root->val==p->val || root->val==q->val) left=root;
    // if(root->val==p->val || root->val==q->val)  right=root;
   
    if((left!=NULL && right!=NULL) || (p==root || q==root)) return root;
    // return NULL;
    return (left!=NULL)?left:right;
}