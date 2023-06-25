class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        /* need to check the square because of:
            1 2 3 4 5 6 7 8 9
            2
            3
            4
            5
            6
            7
            8
            9
            would be true if square are not checked
         */

        vector<vector<bool>> square = vector<vector<bool>>(3, std::vector<bool>(9, false));
        vector<vector<bool>> col = vector<vector<bool>>(9, std::vector<bool>(9, false));

        for (int i = 0; i < board.size(); i++) {
            vector<bool> row(9, false);
            for (int j = 0; j < board[i].size(); j++) {
                // continue if wildcard
                if (board[i][j] == '.') continue;

                int b = board[i][j]-'0'-1;

                if (row[b]) { return false; }
                row[b] = true;
                if (col[j][b]) { return false; }
                col[j][b] = true;

                int idx = j < 6 ? j < 3 ? 0 : 1 : 2; 
                if (square[idx][b]) { return false; }
                square[idx][b] = true;
            }
            // square row reset
            if (i == 2 || i == 5 || i == 8) 
                square = vector<vector<bool>>(3, std::vector<bool>(9, false));
        }
        return true;
    }
};
