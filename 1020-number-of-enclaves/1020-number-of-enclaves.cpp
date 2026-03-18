class Solution {
public:
    int rD[4] = {0, 0, -1, 1};
    int cD[4] = {-1, 1, 0, 0};

    bool isValid(int row, int col, int n, int m) {
        return (row >= 0 && row < n && col >= 0 && col < m);
    }

    void bfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int row, int col, int n, int m) {
        queue<pair<int, int>> q;

        q.push({row, col});
        vis[row][col] = 1;

        while (!q.empty()) {
            auto [cR, cC] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nR = cR + rD[i];
                int nC = cC + cD[i];

                if (isValid(nR, nC, n, m) && grid[nR][nC] == 1 &&
                    vis[nR][nC] == 0) {
                    q.push({nR, nC});
                    vis[nR][nC] = 1;
                }
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) &&
                    vis[i][j] == 0 && isValid(i, j, n, m) && grid[i][j] == 1) {
                    bfs(grid, vis, i, j, n, m);
                }
            }
        }
        int count = 0;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    count++;
                }
            }
        }
        return count;
    }
};