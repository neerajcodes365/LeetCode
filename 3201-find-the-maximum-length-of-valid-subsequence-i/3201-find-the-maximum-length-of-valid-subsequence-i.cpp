class Solution {
public:
    int maximumLength(vector<int>& nums) {
    
    int n=nums.size();
        
        int even= 0, odd= 0;
        int eo= 0, oe= 0;
        
        for (int num: nums) {
            if (num%2==0) {
                even++;
                eo = oe + 1;
            } else {
                odd++;
                oe = eo + 1;
            }
        }
        
        return max({even, odd, eo, oe});
    }
}; 