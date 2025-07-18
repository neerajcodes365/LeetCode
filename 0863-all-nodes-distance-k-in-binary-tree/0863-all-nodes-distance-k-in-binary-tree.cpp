/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void bfs(TreeNode* target,int count,int k,set<TreeNode*>&visited,map<TreeNode*,TreeNode*>&mp,vector<int>&ans){
        if(target==nullptr)return;
        if(count>k)return;
        visited.insert(target);
        if(count==k){
            ans.push_back(target->val);
            return;
        }

        if(target->left && visited.count(target->left)==0) bfs(target->left,count+1,k,visited,mp,ans);
        if(target->right && visited.count(target->right)==0 ) bfs(target->right,count+1,k,visited,mp,ans);
        if(mp[target]&&visited.count(mp[target])==0) bfs(mp[target],count+1,k,visited,mp,ans);


    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*>mp;//child,parent
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* parent=q.front();
            q.pop();
            if(parent->left){
                mp[parent->left]=parent;
                q.push(parent->left);
            }
            if(parent->right){
                mp[parent->right]=parent;
                q.push(parent->right);
            }
        }
        vector<int>ans;
        set<TreeNode*>visited;
        bfs(target,0,k,visited,mp,ans);
        return ans;
    }
};