/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int inorderfind(struct TreeNode * root,int k,int * count){
    if(root==NULL) return -1;
    if(root->left) {
        int left=inorderfind(root->left,k,count);
        if(left!=-1) return left;
    } 
    if(k==(*count) ) return root->val;
    (*count)++;

    if(root->right){
        int right= inorderfind(root->right,k,count);
        if(right!=-1) return right;
    } 
    return -1;
}

int kthSmallest(struct TreeNode* root, int k) {
    int count=1;
    return inorderfind(root,k,&count); 
}