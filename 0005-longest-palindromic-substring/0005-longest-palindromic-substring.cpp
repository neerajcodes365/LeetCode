class Solution {
public:
    string longestPalindrome(string s) {
        int size=s.length();
        int back;
        int front;
        int maxi=1;
        string res;
        int width;
        for(int k=0;k<size;k++){
            back=k-1;
            front=k+1;
            while(  back>-1 && front<size && s[back]==s[front]){
                back--;
                front++;
            }

            // maxi=max(maxi,front-back+1);
             width=front-back-1;
            if(width>maxi){
                res=s.substr(back+1,width);
                maxi=width;
            }

            
            //////////////////////////

            //xabccbay


            back=k;
            front=k+1;
            while(  back>-1 && front<size && s[back]==s[front]){
                back--;
                front++;
            }

            // maxi=max(maxi,front-back+1);
             width=front-back-1;
            if(width>maxi){
                res=s.substr(back+1,width);
                maxi=width;
            }


        }
    return res;
    }
};