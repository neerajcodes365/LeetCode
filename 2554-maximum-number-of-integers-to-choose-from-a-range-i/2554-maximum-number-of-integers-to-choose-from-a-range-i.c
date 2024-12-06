int maxCount(int* banned, int bannedSize, int n, int maxSum) {
    int arr[n];
    for(int i=1;i<=n;i++){
        arr[i-1]=i;
    }
    for(int i=0;i<bannedSize;i++){
        if(banned[i]<=n) arr[banned[i]-1]=0;
    }
    int num=0;
    int sum=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            sum+=arr[i];
            if(sum<=maxSum) num++;
        }
    }
    return num;
}