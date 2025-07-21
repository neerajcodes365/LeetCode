class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int>mp;
            for(int j=i;j<n;j++){
                mp[s[j]]++;
            int lowf=INT_MAX;
            int highf=INT_MIN;
                for(auto [ch,num]:mp){
                lowf=min(lowf,num);
                highf=max(highf,num);
                }
                ans+=(highf-lowf);
            }
        }
        return ans;
    }
};