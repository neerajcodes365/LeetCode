class Solution {
public:
    int help(vector<int>&nums,int mid,int k){
        int ans=1;
        int total=0;
        for(auto i:nums){
            if(total + i>mid){
                ans++;
                total=i;
            }else{
                total+=i;
            }
        }
        return ans;
    }
    int splitArray(vector<int>& nums, int k) {
        int mini=*max_element(nums.begin(),nums.end());
        int total=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            total+=nums[i];
        }
        // int maxi=total;

        int low=mini;
        int high=total;
        int ans=total;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(help(nums,mid,k)<=k){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
return ans;

    }
};

/*
 class Solution {
public:
int mini;
int n;
    void help(vector<int>&nums,int i,int lower,int spi,int k,int maxi){
        if(i>=n){
            if(spi==k){
            int sum=0;
            for(int ii=lower;ii<i;ii++){
            sum+=nums[ii];
            }
                mini=min(mini,max(maxi,sum));
                }
            return ;
            }

        if(spi>=k) return; 
        
        if(spi<k-1){
            int sum=0;
            for(int ii=lower;ii<i;ii++){
                sum+=nums[ii];
            }
            help(nums,i+1,i+1,spi+1,k,max(sum,maxi));
        }
        help(nums,i+1,lower,spi,k,maxi);

    }
    int splitArray(vector<int>& nums, int k) {
         mini=0;  
        n=nums.size();
        help(nums,1,0,0,k,0);
    return mini;    
    }
};
*/