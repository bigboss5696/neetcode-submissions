class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) {
            return false;
        }

        for (int i = 0; i < n; i++) {
            int row_count[10] = {0};
            int col_count[10] = {0};
            for (int j = 0; j < n; j++) {
                int numR = board[i][j] - '0';
                if (numR >= 1 && numR <= 9) {
                    row_count[numR]++;
                    if (row_count[numR] > 1) {
                        return false;
                    }
                }

                int numC = board[j][i] - '0';
                if (numC >= 1 && numC <= 9) {
                    col_count[numC]++;
                    if (col_count[numC] > 1) {
                        return false;
                    }
                }
            }
        }

        for (int box = 0; box < n; ++box) {
            int row_start = (box / 3) * 3;
            int col_start = (box % 3) * 3;

            int box_count[10] = {0};
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; j++) {
                    int num = board[row_start + i][col_start + j] - '0';

                    if (num >= 1 && num <= 9) {
                        box_count[num]++;
                        if (box_count[num] > 1) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};