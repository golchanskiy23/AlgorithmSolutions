class Solution {
public:
    int n,m;
    bool visited[201][201];
    std::vector<int> dirX{0,-1,0,1}, dirY{-1,0,1,0};

    bool isValid(int i, int j){
        if(i < 0 || i >= n || j < 0 || j >= m) return false;
        return true;
    }

    void bfs(int i, int j, vector<vector<char>>& board){
        std::queue<std::pair<int,int>> q;
        q.push({i,j});
        visited[i][j] = true;
        board[i][j] = '#';
        while(!q.empty()){
            auto head = q.front();
            q.pop();
            for(int k = 0; k < 4; k++){
                int currX = head.first+dirX[k], currY = head.second+dirY[k];
                if(isValid(currX, currY) && !visited[currX][currY] && board[currX][currY] == 'O'){
                    visited[currX][currY] = true;
                    board[currX][currY] = '#';
                    q.push({currX, currY});
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        n = board.size(), m = board[0].size();
        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O') bfs(i,0, board);
            if(board[i][m-1] == 'O') bfs(i,m-1, board);
        }

        for(int j = 0; j < m; j++){
            if(board[0][j] == 'O') bfs(0,j, board);
            if(board[n-1][j] == 'O') bfs(n-1,j, board);
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == '#') board[i][j] = 'O';
            }
        }

    }
};