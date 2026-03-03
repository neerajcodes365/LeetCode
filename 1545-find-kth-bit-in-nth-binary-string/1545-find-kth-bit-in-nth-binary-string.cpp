class Solution {
public:
    string ans="0";
    string reversei(string s){

        string h=s;
        int i=0,j=s.size()-1;
        for(int i=0;i<=j;i++){
            if(h[i]=='1')h[i]='0';
            else h[i]='1';
        }
        while(i<=j){
            swap(h[i],h[j]);
            i++;
            j--;
        }
        return h;
    }

    void help(int i,int n){
        if(i>n) return;
        ans=ans+"1"+reversei(ans);
        i++;
        help(i,n);
    }
    char findKthBit(int n, int k) {
        help(0,n);
        // cout<<ans<<endl;
        return ans[k-1];  
    }
};