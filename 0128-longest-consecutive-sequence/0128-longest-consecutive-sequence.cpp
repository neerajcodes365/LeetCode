class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        unordered_set<int> hash;
        for(int i=0;i<nums.size();i++){
            hash.insert(nums[i]);
        }
        int count=1;
        int maxi=1;
        for(auto it:hash){
                maxi=1;

            if(hash.find(it-1)==hash.end()){
                int x=it;
                while(hash.find(x+1)!=hash.end()){
                    x++;
                    maxi++;
                }
            }
            if(maxi>count){
                count=maxi;
            }
        }
        return count;
    }
};