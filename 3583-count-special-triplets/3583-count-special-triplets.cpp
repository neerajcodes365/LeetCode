class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        // map<int,int>
        // map<int,int>count;//element ,count;
        // for(auto it:nums) count[it]++;
        // int ans=0;
        // for(auto [a,b]:count){
        //     if(b>=2 && count.find(a*2)!=count.end()){
        //         // ans+=(1+b-2+count[a*2]);
        //         ans += (b * (b - 1) / 2) * count[a*2]; 
        //     }
        // }
        // return ans;
        unordered_map<int,int>right,left;
        for(auto it:nums) right[it]++;
    
        long long int cnst=1e9+7;
        long long ans=0;

        for(int j=0;j<nums.size();j++){
            int no=nums[j];
            right[no]--;

            int leftcount=left.find(no*2)!=left.end()?left[no*2]:0;
            int rightcount=right.find(no*2)!=right.end()?right[no*2]:0;
    ans=(ans+((long long)leftcount*rightcount)%cnst)%cnst;
        left[no]++;
        }
return ans;
    }
};