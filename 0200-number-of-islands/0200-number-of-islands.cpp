class Solution {
public:

    int rowDir[4] = {-1, 1, 0, 0};
    int colDir[4] = {0, 0, -1, 1};

    bool isValid(int row, int col, int n, int m){
        return (row >= 0 && row<n && col>=0 && col<m);
    }

    void bfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int row, int col, int n, int m){
        queue<pair<int, int>> q;

        q.push({row, col});
        vis[row][col] = 1;

        while(!q.empty()){
            auto[currRow, currCol] = q.front();
            q.pop();

            for(int i=0; i<4; i++){
                int newRow = currRow+rowDir[i];
                int newCol = currCol+colDir[i];

                if(isValid(newRow, newCol, n, m) && grid[newRow][newCol] == '1' && vis[newRow][newCol] == 0){
                    vis[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
        }
    }





    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' && vis[i][j] == 0){
                    bfs(grid, vis, i, j, n, m);
                    count++;
                }
            }
        }
        return count;
    }
};