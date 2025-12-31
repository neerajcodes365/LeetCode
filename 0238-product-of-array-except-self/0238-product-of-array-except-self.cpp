class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefix(n),sufix(n);

        int mul=1;
        // prefix[0]=nums[0]==0?1:nums[0];
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]*nums[i];
        }
        // sufix[n-1]=nums[n-1]==0?1:nums[n-1];
        sufix[n-1]=nums[n-1];
         for(int i=n-2;i>=0;i--){
            sufix[i]=sufix[i+1]*nums[i];
        }
        vector<int>ans;
    for(int i=0;i<n;i++){
        if(i==0)ans.push_back(sufix[i+1]);
        else if(i==n-1) ans.push_back(prefix[n-2]);
        else ans.push_back(prefix[i-1]*sufix[i+1]);
    }
return ans;
    }
};