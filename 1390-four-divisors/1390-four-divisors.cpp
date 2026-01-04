class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int count=0;
            int helpsum=0;
            for(int j=2;j<=sqrt(nums[i]);j++){
                if(nums[i]%j==0){
                    count++;
                    helpsum+=j;
                    // cout<<"helpsum "<<helpsum<<endl;
                    if(j!=nums[i]/j)helpsum+=nums[i]/j;
                    else count++;
                    // cout<<"helpsum "<<helpsum<<endl;
                }
            }
            // cout<<count<<endl;
            if(count==1)ans+=helpsum+1+nums[i];
        }
        return ans;
    }
};