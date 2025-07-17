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
    void help(TreeNode* root,int row,int col,vector<tuple<int,int,int>>&store){
        if(root==nullptr)return;
store.push_back({col,row,root->val});
if(root->left) help(root->left,row+1,col-1,store);
if(root->right) help(root->right,row+1,col+1,store);

    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int,int,int>>store;
        help(root,0,0,store);
        sort(store.begin(),store.end());

        vector<vector<int>>ans;
       
        map<int,vector<int>>mp;

        for(int i=0;i<store.size();i++){
            int coli=get<0>(store[i]);
            int rowi=get<1>(store[i]);
            int nodeval=get<2>(store[i]);
            
            mp[coli].push_back(nodeval);

        }
        for(auto [col,vec]:mp){
            ans.push_back(vec);
        }

        return ans;
    }
};