class Solution {

    int help(int n,int k){

    if(n==1 && k==1) return 0;
    if(n==2 && k==1) return 0;
    if(n==2 && k==2) return 1;
    int ans;
    int total=pow(2,n);
    
    if(k>total/2){
        // flag=(flag+1)%2;
        ans=help(n,k-total/2);
        if(ans==0) return 1; 
        else return 0;
    }
    else{
        ans= help(n-1,k);
    }
return ans;
}

public:
    int kthGrammar(int n, int k) {
        // k--;
    //     int arr[]={0,1,1,0};
    //     int cnt4k=1;
    //     int index=0;
    //     int mark=1;
    //     while(cnt4k!=k){
    //         cnt4k++;
    //         index=(index+1)%4;
    //         if(index==0)mark++;
    //     }
    //     if(mark%2==0){
    //         return arr[index]==1?0:1;
    //     }

    // return arr[index];


    // if(n==1 && k==1) return 0;
    // flag=0;
    // if(flag)return ans==1?0:1;

    int ans=help(n,k);
    return ans;
    }
};