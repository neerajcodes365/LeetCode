class Solution {
public:
    int minPartitions(string n) {
        // return 5;
        int maxi=INT_MIN;
        for(int i=0;i<n.size();i++){
            int a=n[i]-'0';
            maxi=max(maxi,a);
        }
        return maxi;



    }
};