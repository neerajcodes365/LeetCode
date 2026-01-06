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
    int maxLevelSum(TreeNode* root) {
        int ans=1;
        int maxi=root->val;
        int level=1;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            // vector<int>forsum;
            int sum=0;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode * temp=q.front();
                q.pop();
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
                sum+=temp->val;
            }
            // int sum=0;
            if(sum>=maxi){
                ans=level;
                maxi=sum;
            }
            level++;
        }
        return ans;
        
    }
};