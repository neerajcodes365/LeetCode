class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                int a=nums[i];
                int b=nums[j];
                long long req= 1LL*target-(a+b);
                int l=j+1;
                int r=n-1;
                while(l<r && l<n && r>-1){
                    long long sum=nums[l]+nums[r];
                    if(sum==req){
                        vector<int>aa;
                        aa.push_back(a);
                        aa.push_back(b);
                        aa.push_back(nums[l]);
                        aa.push_back(nums[r]);
                        ans.push_back(aa);
                         l++;
                         r--;
                    while( l<r && l<n-1 && nums[l]==nums[l-1]) l++;
                    while( l<r && r>0 && nums[r]==nums[r+1]) r--;
                }
                else if(sum>req) r--;
                else l++;
            }
        }
    }
        return ans;
    }
};