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
    TreeNode* reverseOddLevels(TreeNode* root) {
        TreeNode* temp;
        int level=0;
        int f=0;
        int r=0;
        int levelsize;
        queue<TreeNode*> que;
        que.push(root);
        r++;
        level++;
        while(f<r){
            levelsize=r-f;
            while(levelsize!=0){
                 temp=que.front();
                 que.pop();
                 f++;
            if(temp->left){
                que.push(temp->left);
                r++;
                }
            if(temp->right){
                que.push(temp->right);
                r++;
            }
            levelsize--;
            }
            level++;
            if (level % 2 == 0) {
                int left = 0;
                int right = que.size() - 1;
                vector<TreeNode*> arr;

                for (int i = 0; i < que.size(); ++i) {
                    TreeNode* node = que.front();
                    arr.push_back(node);
                    que.pop();
                    que.push(node);
                }

                while (left < right) {
                    swap(arr[left]->val, arr[right]->val);
                    left++;
                    right--;
                }  
            }

        }
        return root;}
};