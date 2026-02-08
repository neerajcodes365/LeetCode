class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign=1;
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if( (dividend<0 && divisor<0) || (dividend>0 && divisor>0) ) sign=1;
        else sign=-1;
         long long int divi=llabs(dividend);
         long long int divis=llabs(divisor);
        long long int sum=0;

        while(divi>=divis){
            int i=0;
            while((divis<<i)<=divi){
                i++;
            }
            sum+=1ll<<(i-1);
            divi-=divis<<(i-1);
        }
        return sum*sign;
        //
    }
};