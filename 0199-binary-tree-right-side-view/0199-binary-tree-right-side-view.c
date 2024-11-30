/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int max(int a,int b){
    return a>b?a:b;
 }
 int heightoftree(struct TreeNode * root){
    if(root==NULL) return 0;
    int left=heightoftree(root->left);
    int right=heightoftree(root->right);
    return max(left,right)+1;
 }
void helper(struct TreeNode *root,int * arr,int level,int *top){
    if(root==NULL) return ;
    if(level==(*top)){
        arr[(*top)]=root->val;
        (*top)++;
    }
    if(root->right) helper(root->right,arr,level+1,top);
    if(root->left) helper(root->left,arr,level+1,top);
    }
int* rightSideView(struct TreeNode* root, int* returnSize) {
    int height=heightoftree(root);
    *returnSize=height;
    int* arr=(int * )malloc(sizeof(int)*height);
    int top=0;
    int level=0;
    helper(root,arr,level,&top);
    return arr;
}