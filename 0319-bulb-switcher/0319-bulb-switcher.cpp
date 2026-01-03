class Solution {
public:
    int bulbSwitch(int n) {
        int ans=0;
        for(int i=1;i<=sqrt(n);i++){
            ans++;
        }
        return ans;
    }
};