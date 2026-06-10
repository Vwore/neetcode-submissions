class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        // check rows
        for (int i = 0; i < n; i++) {
            unordered_set<char> st;
            for (int j = 0; j < n; j++) {
                if (st.find(board[i][j]) != st.end()) {
                    cout<<"row"<<i<<j;
                    return false;
                }
                if(board[i][j] != '.') st.insert(board[i][j]);
            }
        }

        for (int i = 0; i < n; i++) {
            unordered_set<char> st;
            for (int j = 0; j < n; j++) {
                if (st.find(board[j][i]) != st.end()) {
                    cout<<"col"<<i<<j;
                    return false;
                }
               if(board[j][i] != '.') st.insert(board[j][i]);
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                unordered_set<char> st;
                int startI = 3 * i, startJ = 3 * j;
                for (int k = startI; k < startI + 3; k++) {
                    for (int l = startJ; l < startJ + 3; l++) {
                        if (st.find(board[k][l]) != st.end()) {
                            cout<<"mat"<<k<<l;
                            return false;
                        }
                        if(board[k][l] != '.') st.insert(board[k][l]);
                    }
                }
            }
        }

        return true;
    }
};
