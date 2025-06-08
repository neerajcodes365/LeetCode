class Solution {
public:
    int search(vector<int>& nums, int target) {
        // int count=0;
        // for(auto it:nums){
        //     if(it==target) return count;
        //     count++;
        // }
        // return -1;

        int lt=0,rt=nums.size()-1;
        int mid;
        while(lt<=rt){
            mid=(lt+rt)/2;
        if(nums[mid]==target){
            return mid;
        }
        if(nums[mid]>=nums[lt]){
            if(target<=nums[mid] && target>=nums[lt]){
                rt=mid-1;
            }else lt=mid+1;
        }else{
            if(target<=nums[rt] && target>=nums[mid]){
                
                lt=mid+1;
            }else rt=mid-1;
        }
    }
    return -1;
    }
};