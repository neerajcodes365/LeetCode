class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int sum=0;
            set<int>sett;
            for(int j=i;j<n;j++){
                sett.insert(nums[j]);
                sum+=nums[j];
                if(sett.count(sum))ans++;
            }
        }
        return ans;
    }
};