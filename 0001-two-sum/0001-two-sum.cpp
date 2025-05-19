class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int>ans;
        unordered_set<int,int>hash;
        for(int i=0;i<nums.size();i++){
            hash.inset({nums[i],i});
        }
        for(int i=0;i<nums.size();i++){
            int other=targert-nums[i];
            if(hash.find(other)!=hash.end()){
                ans.push_back(i);

            }
        }
    }
};