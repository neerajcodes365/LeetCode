class Solution {
public:
    string reverseWords(string s) {
        // while(s[i]!='\0' && s[i]!='\n'){

        // }
        string ans="";
        int len=0;
        for(int i=s.length()-1;i>=0;i--){
            // if('a'<=s[i] && 'z'>=s[i]){
                if(isalpha(s[i]))len++;
            // }else if('a'<=s[i+1] && 'z'>=s[i+1]){
                else if(len>0){
                ans+=s.substr(i+1,len);
                ans+=" ";
                len=0;
            }
        }

        if(len > 0) {
            ans += s.substr(0, len);
        }

        while(!ans.empty() && ans.back() == ' ') {
                    ans.pop_back();
                }
        return ans;
    }
};