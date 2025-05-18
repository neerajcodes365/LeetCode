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
