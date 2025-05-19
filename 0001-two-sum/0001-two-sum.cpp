class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int>ans;
        unordered_map<int,int>hash;
        for(int i=0;i<nums.size();i++){
            hash.insert({nums[i],i});
        }
        for(int i=0;i<nums.size();i++){
            int other=target-nums[i];
            if(hash.find(other)!=hash.end() && hash[other]!=i){
                ans.push_back(i);
                ans.push_back(hash[other]);
                return ans;
            }
        }
        return ans;
    }
};