class Solution {
public:

    int rowDir[4] = {1, -1, 0, 0};
    int colDir[4] = {0, 0, 1, -1};

    bool isValid(int row, int col, int n, int m){
        return (row >= 0 && row < n && col >= 0 && col < m);
    }

    void bfs(vector<vector<char>>& board,
             vector<vector<int>>& vis,
             int row, int col,
             int n, int m){

        queue<pair<int,int>> q;
        q.push({row, col});
        vis[row][col] = 1;
        board[row][col] = 'A';

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            int currRow = p.first;
            int currCol = p.second;

            for(int i = 0; i < 4; i++){
                int newRow = currRow + rowDir[i];
                int newCol = currCol + colDir[i];

                if(isValid(newRow, newCol, n, m) &&
                   board[newRow][newCol] == 'O' &&
                   vis[newRow][newCol] == 0){

                    vis[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                    board[newRow][newCol] = 'A';
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int j = 0; j < m; j++){
            if(board[0][j] == 'O' && vis[0][j] == 0)
                bfs(board, vis, 0, j, n, m);

            if(board[n-1][j] == 'O' && vis[n-1][j] == 0)
                bfs(board, vis, n-1, j, n, m);
        }

        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O' && vis[i][0] == 0)
                bfs(board, vis, i, 0, n, m);

            if(board[i][m-1] == 'O' && vis[i][m-1] == 0)
                bfs(board, vis, i, m-1, n, m);
        }


        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                // if(board[i][j] == 'O' && vis[i][j] == 0)
                //     board[i][j] = 'X';
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                
                else if(board[i][j] == 'A')
                board[i][j] = 'O';

                
            }
        }
    }
};
