class Solution {
public:
    long long coloredCells(int n) {
        return 1ULL+(4ULL*(n-1)*n)/2;
    }
};