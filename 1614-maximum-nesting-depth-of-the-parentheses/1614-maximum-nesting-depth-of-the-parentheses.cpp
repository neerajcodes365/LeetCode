class Solution {
public:
    int maxDepth(string s) {
        int maxi=0;
        int br=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') br++;
            else if(s[i]==')')br--;
            maxi=max(maxi,br);
        }
        return maxi;
    }
};