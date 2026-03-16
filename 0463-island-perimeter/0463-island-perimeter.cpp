class Solution {
public:
    int rowDir[4] = {1, -1, 0, 0};
    int colDir[4] = {0, 0, 1, -1};

    bool isValid(int row, int col, int n, int m) {
        return (row >= 0 && row < n && col >= 0 && col < m);
    }

    int bfs(int row, int col, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& vis) {

        queue<pair<int, int>> q;
        int perimeter = 0;

        q.push({row, col});
        vis[row][col] = 1;

        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            int pRow = p.first;
            int pCol = p.second;

            perimeter += 4;

            for (int i = 0; i < 4; i++) {
                int newRow = pRow + rowDir[i];
                int newCol = pCol + colDir[i];

                if (isValid(newRow, newCol, n, m) &&
                    grid[newRow][newCol] == 1) {
                    perimeter--;



                    if (vis[newRow][newCol] == 0) {
                        vis[newRow][newCol] = 1;
                        q.push({newRow, newCol});
                    }
                }
            }
        }
        
        return perimeter;
    }

    int islandPerimeter(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {

                    return bfs(i, j, n, m, grid, vis);
                }
            }
        }
        return 0;
    }
};