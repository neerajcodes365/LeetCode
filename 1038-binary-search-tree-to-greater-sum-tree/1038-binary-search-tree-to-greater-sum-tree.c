/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 struct TreeNode* help(struct TreeNode * root,int * sum){
    if(root==NULL) return NULL;
    if(root->right) root->right=help(root->right,sum);
   // if(root!=NULL){
    int temp=root->val;
    root->val=root->val+(*sum);
    (*sum)+=temp;
   // return root;
  //  }
    if(root->left) root->left=help(root->left,sum);
   return root;

 }
struct TreeNode* bstToGst(struct TreeNode* root) {
    int sum=0;
    return help(root,&sum);
    
}