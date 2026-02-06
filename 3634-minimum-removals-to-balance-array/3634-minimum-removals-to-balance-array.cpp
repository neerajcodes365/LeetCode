class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        // if(n<=2) return 0;
        int mini=INT_MAX;
        for( auto it=nums.begin(); it!=nums.end() ;it++){
            int val=*(it);
            
            auto itend=upper_bound(it+1,nums.end(),val*k);
            
            // if(itend!=nums.end()&& (*itend)=k*(*it)){

                int rest=n-(itend-it+1);
                mini=min(mini, rest);
            
        }
        return mini+1;
        
    }
};