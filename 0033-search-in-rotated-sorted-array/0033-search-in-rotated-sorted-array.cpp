class Solution {
public:
    int search(vector<int>& nums, int target) {
        int count=0;
        for(auto it:nums){
            if(it==target) return count;
            count++;
        }
        return -1;
    }
};