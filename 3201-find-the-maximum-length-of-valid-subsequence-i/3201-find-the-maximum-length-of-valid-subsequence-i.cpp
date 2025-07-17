class Solution {
public:
    int maximumLength(vector<int>& nums) {
    
    int n=nums.size();
        
        int evenCount= 0, oddCount= 0;
        int eoLength= 0, oeLength= 0;
        
        for (int num: nums) {
            if (num%2==0) {
                evenCount++;
                eoLength = oeLength + 1;
            } else {
                oddCount++;
                oeLength = eoLength + 1;
            }
        }
        
        return max({evenCount, oddCount, eoLength, oeLength});
    }
};