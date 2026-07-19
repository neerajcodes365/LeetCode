class Solution {
public:
    long long maximumValue(int n, int s, int m) {
    long long ss = s, mm = m, nn = n; 
        long long x = ss + n / 2 * mm - ((n - 1) / 2 ); 
        if(n == 1) return ss; 
        return n % 2 == 0 ? x : x + 1;  
    }
};