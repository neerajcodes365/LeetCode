// class Solution {
// private:
//     double help(double x,int n,double count,double sum){
//         if(count==n-1) return sum;
//         else{
//             sum=sum*x;
//             count++;
//             return help(x,n,count,sum);
//         }
//     }
// public:
//     double myPow(double x, int ni) {
//         if(x==1) return x;
//         if(ni==0){
//             int i=1;
//             return (double)i;}
//         if(ni<0){
//             double n=(double)ni;
//             double a=help(x,abs(n),0,x);
//             return 1/a;
//         }
//         else{
//             double n=(double)ni;
//             return help(x,n,0,x);
//         }
//     }
// };
// //0.44528 //0
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;

        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double result = 1;
        while (N > 0) {
            if (N % 2 == 1) result *= x;
            x *= x;
            N /= 2;
        }
        return result;
    }
};
