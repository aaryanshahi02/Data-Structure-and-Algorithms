class Solution {
public:

    int rowDir[4] = {-1, 1, 0, 0};
    int colDir[4] = {0, 0, -1, 1};

    bool  isValid(int row, int col, int n, int m){
        return(row >= 0 && row < n && col >= 0 && col < m);
    }

    

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();

        int u = entrance[0];
        int v = entrance[1];

        vector<vector<int>> ans(n, vector<int> (m, 1e9));
        queue<pair<int, int>> q;

        q.push({u, v});
        ans[u][v] = 0;

        while(!q.empty()){
            auto[currRow, currCol] = q.front();
            q.pop();

            for(int i=0; i<4; i++){
                int newRow = currRow + rowDir[i];
                int newCol = currCol + colDir[i];

                if(isValid(newRow, newCol, n, m) && ans[newRow][newCol] == 1e9 && maze[newRow][newCol] == '.'){
                    q.push({newRow, newCol});
                    ans[newRow][newCol] = ans[currRow][currCol] + 1;
                }
            }
        }

        int mini = 1e9;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if((i==0 || i==n-1 || j==0 || j==m-1) && !(i==u && j==v)){
                    mini = min(mini, ans[i][j]);
                }
            }
        }
        return (mini == 1e9) ? -1 : mini;
        
    }
};