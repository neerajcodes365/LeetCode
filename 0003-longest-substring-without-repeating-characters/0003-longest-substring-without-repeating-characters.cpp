class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        map<char,int>mp;
        int i=0;
        for(int j=0;j<s.size();j++){
            mp[s[j]]++;
            // j++;
            while(mp[s[j]]>1){
                mp[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};