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
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long ans=0;
        if (root==nullptr)return ans;

        queue<pair<TreeNode*,unsigned long long >>q;
        q.push({root,1});
        while(!q.empty()){

            int size=q.size();

            vector<pair<TreeNode*,unsigned long long >>level;

            for(int i=0;i<size;i++){
                auto[node,index]=q.front();
                q.pop();
                if(node->left)q.push({node->left,2*index});
                if(node->right)q.push({node->right,2*index+1});
                level.push_back({node,index});
            }
            ans=max(ans, level[size-1].second-level[0].second);
        }
        return ans+1;
    }
};