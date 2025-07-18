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
    typedef TreeNode node;
int n;
    node *help(vector<int>& preorder, vector<int>& inorder,int start,int end,int& index4pre,map<int,int>&mp){
        if(index4pre>=n)return nullptr;
        if(start>end)return nullptr;
        node* root=new node;
        root->val=preorder[index4pre];
        int index=mp[preorder[index4pre]];
        index4pre++;
        root->left=help(preorder,inorder,start,index-1,index4pre,mp);
        root->right=help(preorder,inorder,index+1,end,index4pre,mp);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;//preorder element,inorder index
         n=preorder.size();
        
        //  for(int i = 0; i < n; i++) {
        //     mp[inorder[i]] = i;
        // }
        for(int i=0;i<n;i++) mp[inorder[i]]=i;
        // root->val=preorder[0];
        int index4pre=0;
        node* a=help(preorder,inorder,0,n-1,index4pre,mp);
        return a;
    }
};