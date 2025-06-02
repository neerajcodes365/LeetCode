class Solution {
public:
    bool solved = false;

    bool check(vector<vector<char>>& board, int row, int col, char ch) {
        for (int i = 0; i < 9; ++i) {
            if (board[row][i] == ch) return false;
            if (board[i][col] == ch) return false;
            if (board[3*(row/3) + i/3][3*(col/3) + i%3] == ch) return false;
        }
        return true;
    }

    void help(vector<vector<char>>& board, int row, int col) {
        if (row == 9) {
            solved = true;
            return;
        }
        if (col == 9) {
            help(board, row + 1, 0);
            return;
        }
        if (board[row][col] != '.') {
            help(board, row, col + 1);
            return;
        }

        for (char ch = '1'; ch <= '9'; ++ch) {
            if (check(board, row, col, ch)) {
                board[row][col] = ch;
                help(board, row, col + 1);
                if (solved) return;
                board[row][col] = '.';
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        help(board, 0, 0);
    }
};
