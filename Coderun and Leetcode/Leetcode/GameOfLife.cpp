class Solution {
public:
    int x[8]={-1,-1,0,1,1,1,0,-1};
    int y[8]={0,1,1,1,0,-1,-1,-1};
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        auto ans = board;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                int neighbors = 0;
                for(int k = 0; k < 8; ++k){
                    if(i+x[k] >= 0 && i+x[k] < n && j+y[k] >= 0 && j+y[k] < m){
                        if(board[i+x[k]][j+y[k]] == 1){
                            neighbors++;
                        }
                    }
                }
                if(board[i][j] == 1 && (neighbors < 2 || neighbors > 3)) ans[i][j] = 0;
                else if(board[i][j] == 0 && (neighbors == 3)) ans[i][j] = 1; 
            }
        }
        board = ans;
    }
};