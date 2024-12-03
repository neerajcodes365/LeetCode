/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maax(int a,int b){
    return a>b?a:b;
 }
void help(struct TreeNode* root,int dir,int length,int*max){
    if(root == NULL) return;
    *max=maax((*max),length);
    if(dir==0){
        help(root->left,0,1,max);
        help(root->right,1,length+1,max);
    }else{//dir 1
        help(root->left,0,length+1,max);
        help(root->right,1,1,max);
    }
    return ;
 }
int longestZigZag(struct TreeNode* root) {
    int max=0;
    //left 0 //right 1
    if(root->left)help(root->left,0,1,&max);
    if(root->right)help(root->right,1,1,&max);
    return max;
}