/*  TLE ;/
class Solution {
private:
    void help(int row, int col, int m, int n) {
        if (row == m - 1 && col == n - 1) {
            count++;
            return;
        }
        if (row < m - 1) help(row + 1, col, m, n);
        if (col < n - 1) help(row, col + 1, m, n);
    }

public:
    int count = 0;

    int uniquePaths(int m, int n) {
        count = 0; 
        help(0, 0, m, n);
        return count;
    }
};

*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m + n - 2;
        int r = min(m - 1, n - 1); // Choose the smaller one to optimize
        long long res = 1;

        for (int i = 1; i <= r; ++i) {
            res = res * (N - r + i) / i;
        }

        return (int)res;
    }
};



