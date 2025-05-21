class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)return 0;
        unordered_set<char>hash;
        int maxi=1;
        int count=1;
        int l=0;
        hash.insert(s[l]);

        for(int r=1;r<s.size();r++){
            if(hash.find(s[r])==hash.end() ){
                count++;
                hash.insert(s[r]);
                if(count>maxi) maxi=count;
            }else{
                hash.erase(s[l]);
                r--;
                l++;
                count=hash.size();
            }
        }
        return maxi;
    }
};