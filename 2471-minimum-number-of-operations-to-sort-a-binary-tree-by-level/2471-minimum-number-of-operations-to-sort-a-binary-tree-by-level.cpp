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
    int minimumOperations(TreeNode* root) {
        if (!root) return 0;

        int count = 0;
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            int levelSize = que.size();
            vector<int> levelValues;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = que.front();
                que.pop();
                levelValues.push_back(node->val);

                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }

            count += minSwapsToSort(levelValues);
        }

        return count;
    }

private:
    int minSwapsToSort(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> indexedArr(n);

        for (int i = 0; i < n; ++i) {
            indexedArr[i] = {arr[i], i};
        }

        sort(indexedArr.begin(), indexedArr.end());

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; ++i) {
            if (visited[i] || indexedArr[i].second == i) continue;

            int cycleSize = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = indexedArr[j].second;
                cycleSize++;
            }

            if (cycleSize > 1) {
                swaps += cycleSize - 1;
            }
        }

        return swaps;
    }
};
