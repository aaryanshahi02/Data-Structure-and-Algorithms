class Solution {
public:

    int rowDir[8] = {0, 0, -1, 1, -1, 1, 1, -1};
    int colDir[8] = {-1, 1, 0, 0, 1, 1, -1, -1};

    bool isValid(int row, int col, int n, int m){
        return (row>=0 && row<n && col>=0 && col<m);
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // int count = 0;
        queue<tuple<int, int, int>> q;
        vector<vector<int>>vis(n, vector<int> (m,0));

        if(grid[0][0] != 0 || grid[n-1][n-1] != 0){
            return -1;
        }

        q.push({0, 0, 1});
        vis[0][0] = 1;

        // int count = 1;

        while(!q.empty()){
            auto [currRow, currCol, currDist] = q.front();
            q.pop();
            // int currRow = p.first;
            // int currCol = p.second;
            // int currDist = p.third;

            if(currRow == n-1 && currCol == m-1){
                return currDist;
            }

            for(int i=0; i<8; i++){
                int newRow = currRow + rowDir[i];
                int newCol = currCol + colDir[i];
                int newDist = currDist + 1;

                if(isValid(newRow, newCol, n, m) && vis[newRow][newCol] == 0 && grid[newRow][newCol] == 0){
                    vis[newRow][newCol] = 1;
                    q.push({newRow, newCol, newDist});
                }
            }
            

            

        }
        return -1;


    }
};