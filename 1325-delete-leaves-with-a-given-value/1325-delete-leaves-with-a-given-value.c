/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* removeLeafNodes(struct TreeNode* root, int target) {
    if(root==NULL) return NULL;
    if(root->left) root->left=removeLeafNodes(root->left,target);
    if(root->right) root->right=removeLeafNodes(root->right,target);
    if(root->left==NULL && root->right==NULL && root->val==target){
        free(root);
        return NULL;
    }
    return root;
    // return root;
}
/* did for learning / no other purpose
void helperfun(struct TreeNode * rootprv,struct TreeNode * root,int target){
    if(root==NULL) return;
    if(root->left){
        rootprv=root;
         return helperfun(rootprv,root->left,target);
         }
    if(root->right){
        rootprv=root;
     return helperfun(rootprv,root->right,target);
     }
    if(root->left==NULL && root->right==NULL && root->val==target){
        struct TreeNode * temp=root;
        free(temp);
        rootprv->right=NULL;
        rootprv->left=NULL;
return ;

    }
}

*/

