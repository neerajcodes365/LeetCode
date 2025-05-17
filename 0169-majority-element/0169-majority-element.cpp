/*       NlogN 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0;
        int j;
        int finalnum=(int)floor(nums.size()/2);//floor returns double;
        for(int i=0;i<nums.size()-1;i++){
            if(count==finalnum) {
                j=i;
                break;
                }
            if(nums[i]==nums[i+1]){
                count++;
            }else{
                count=0;
            }
        }
        return nums[j];
    }
};

*/

//O(N)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
       // sort(nums.begin(),nums.end());
       int count=0;
       int leader;
       for(int i=0;i<nums.size();i++){
        if(count==0){
            leader=nums[i];
            count=1;
        }
        if(nums[i]==leader) count++;
        else count--;
       }
       return leader;
    }
};