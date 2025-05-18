class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        map<int, int> mapp;
        
        for(int i = 0; i < nums.size(); i++) {
            mapp[nums[i]] += 1;
        }
        
        for(auto it : mapp) {
            if(it.second > (int)(nums.size() / 3)) {
                ans.push_back(it.first);
            }
        }
        
        return ans;
    }
};
