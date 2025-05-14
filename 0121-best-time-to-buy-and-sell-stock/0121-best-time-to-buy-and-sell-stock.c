int maxProfit(int* prices, int pricesSize) {
    int flag =0;
     if (pricesSize <= 1) return 0;
     int l=0,r=0,max=0,count=0;
    while(r<pricesSize && l<pricesSize){
        if((prices[r]-prices[l])>0){
            max=(prices[r]-prices[l]);
            if(max>count) count=max;
        }
        else{
            l=r;
        }
        r++;
    }
    return count;
    
}