/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 struct TreeNode* createnode(int val){
    struct TreeNode* node=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val=val;
    node->right=node->left=NULL;
    return node;
}
int findindex(int * inorder,int inordersize,int num){
    for(int i=0;i<inordersize;i++){
        if(inorder[i]==num) return i;
    }
    return -1;
}
struct TreeNode* help(int start,int end,int *inorder,int *postorder,int inorderSize,int* size){
     if (start > end) return NULL;
    int index=findindex(inorder,inorderSize,postorder[(*size)-1]);
    (*size)--;
    struct TreeNode* root=createnode(inorder[index]);
    root->right=help(index+1,end,inorder,postorder,inorderSize,size);
    root->left=help(start,index-1,inorder,postorder,inorderSize,size);
    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
   // int tofindnum=frompost(postorder,i);
   // int index=frominorder(inorder);
   int size=postorderSize -1;
    int index=findindex(inorder,inorderSize,postorder[postorderSize-1]);
    struct TreeNode* root=createnode(inorder[index]);
    root->right=help(index+1,inorderSize-1,inorder,postorder,inorderSize,&size);
    root->left=help(0,index-1,inorder,postorder,inorderSize,&size);
    return root;
}