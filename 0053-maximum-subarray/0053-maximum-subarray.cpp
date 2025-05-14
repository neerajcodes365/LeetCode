class Solution {
public:
    int maxSubArray(vector<int>& n) {//kadane's algo ,divide and conquer nokanam
        int sum=0;
        int max=INT_MIN;
        for(int i=0;i<n.size();i++){
            sum+=n[i];
            if(sum>max) max=sum;
            if(sum<0) sum=0;
        }
        return max;
    }
};