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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>>ans;
        if(root==nullptr)return ans;
        queue<TreeNode*>q;
        int count=0;
        q.push(root);
        while(!q.empty()){

            vector<int>level;
            int size=q.size();
                // level.push_back()
                for(int i=0;i<size;i++){
                    TreeNode * node=q.front();
                    level.push_back(node->val);
                    q.pop();
                    if(node->left)q.push(node->left);
                    if(node->right)q.push(node->right);
                }
                if(count%2==0) {
                    ans.push_back(level);
                    count++;
                    }
                else{
                    reverse(level.begin(),level.end());
                    ans.push_back(level);
                    count++;
                    }
            }

        return ans;

    }
};