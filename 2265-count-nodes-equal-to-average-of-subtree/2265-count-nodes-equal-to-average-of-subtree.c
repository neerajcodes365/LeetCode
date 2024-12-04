/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct set {
    int sum;
    int tnodes;
};

typedef struct set set;


set help(struct TreeNode* root, int* count) {
set result = {0, 0};

    if (root == NULL) return result;

    set left = help(root->left, count);
    set right = help(root->right, count);

    result.sum = left.sum + right.sum + root->val;
    result.tnodes = left.tnodes + right.tnodes + 1;

    if (result.sum / result.tnodes == root->val) {
        (*count)++;
    }

    return result;
}

int averageOfSubtree(struct TreeNode* root) {
    int count = 0;
    help(root, &count);
    return count;
}


/*int help (struct TreeNode * root,int * count){
    if(root==NULL)return 0;

    int left=help(root->left,count);
    int right=help(root->right,count);
                                            // tnodes ?
    int sum=left+right+root->val;
    if((sum/tnodes)==(root->val)){
        (*count)++;
    }
    return sum;
}
int averageOfSubtree(struct TreeNode* root) {
    int count=0;
    // int tnodes
   int a= help(root,&count);
    return count;
}*/