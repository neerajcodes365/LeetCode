class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> hash;

        for (auto it : nums) {
            hash[it]++;
        }

        vector<vector<int>> result(n + 1);
        for (auto it = hash.begin(); it != hash.end(); it++) {
            result[it->second].push_back(it->first);
        }

        vector<int> ans;
        int count = 0;

        for (int i = n; i >= 0 && count < k; i--) {
            for (auto it : result[i]) {
                ans.push_back(it);
                count++;
                if (count == k) break;
            }
        }

        return ans;
    }
};
