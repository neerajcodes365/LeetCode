class Solution {
public:
    string help(string &ans){
        string temp="";
            char num=ans[0];
            int count=1;
            // int m=0;

        for(int i=1;i<ans.length();i++){
            if(ans[i]==num){
                count++;
            }else{
                // temp[m++]='0'+count;
                // temp[m++]=num;
                temp.push_back('0'+count);
                temp.push_back(num);
                num=ans[i];
                count=1;
            }
        }
        temp.push_back('0' + count);
        temp.push_back(num);
        return temp;
    }
    string countAndSay(int n) {
        if(n==1) return "1";
        string ans="1";
        for(int i=1;i<n;i++){
            ans=help(ans);
        }
        return ans;
    }
};