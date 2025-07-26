class Solution {
public:
    // int ans;
    // void help(int n,vector<int>&pr){
    //     if(n<=1)return;
    //     if(n==2) {
    //     // ans++;
    //     pr[2]=1;
    //     return;
    //     }
    //     if(n<=3){
    //                 pr[2]=1;
    //                 pr[3]=1;
    //         return;
    //     }
    //     for(int i=5;i<n;i+=6){
    //         int back=i;
    //         int front=i+2;
    //         // if(n%back==0)
    //         if(back<n) pr[back]=1;
    //         if(front<n) pr[front]=1;
    //     }


    

    int countPrimes(int n) {
        int ans=0;

        vector<int>pr(n,0);
       
       for(long long int i=2;i<n;i++){
        if(pr[i]==0){
            for(long long int j=i*i;j<n;j+=i){
                pr[j]=1;
            }
        }
       }



        for(int i=2;i<n;i++){
            if(pr[i]==0)ans++;
        }
        return ans;
    }
};