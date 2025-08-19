class Solution {
public:
    string breakPalindrome(string s) {
        // ans="";
        int n=s.length();
        if(n==1) return "";
        // int i=0;
        // int j=n-1;
        // while(i<=j){

        // }
        // s[0]=(s[0]+1)%25;
        // if(s[0]=='z'){
        //     s[0]='a';
        // }else{
        //     s[0]=s[0]+1;
        // }
        // int flag=0;
        // for(int i=0;i<n-1;i++){
        //     if(s[i]<s[i+1]){
        //         s[i+1]=s[i];
        //         flag=1;
        //         break;
        //     }
        // }
        // // cout<<s<<endl;
        // if(flag==0){
        //      if(s[n-1]=='z') s[n-1]='a';
        //      else s[0]=s[0]+1;
        // }
        int flag=0;
        for(int i=0;i<n/2;i++){
            if(s[i]!='a'){
                if(i==n/2)s[i]='b';
                else s[i]='a';
                flag=1;
                break;
            }
        }
        if(flag==0){
            s[n-1]='b';
        }

        return s;
    }
};