class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        // cout<<((n/3)+1)<<endl;
        vector<int>ans;
        for(auto [a,b]:mp){
            // cout<<a<<" "<<b<<endl;
            if(b>=((n/3)+1)) ans.push_back(a);
        }
        return ans;
    }
};