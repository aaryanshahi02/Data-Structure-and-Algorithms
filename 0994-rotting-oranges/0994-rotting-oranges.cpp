class Solution {
public:
    int rowDir[4] = {-1, 1, 0, 0};
    int colDir[4] = {0, 0, -1, 1};

    bool isValid(int row, int col, int n, int m){
        return(row >=0 && row < n && col >= 0 && col < m);
    }


    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int> (m, 0));
        queue<pair<int, int>> q;

        int minutes = 0;
        int fresh = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1) fresh++;

                else if(grid[i][j] == 2){ 
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
    

        while(!q.empty()){
            int size  = q.size();
            bool flag = false;

            while(size>0){
                size--;
                auto[currRow, currCol] = q.front();
                q.pop();

                for(int i=0; i<4; i++){
                    int newRow = currRow + rowDir[i];
                    int newCol = currCol + colDir[i];

                    if(isValid(newRow, newCol, n, m) && vis[newRow][newCol] == 0 && grid[newRow][newCol] == 1){
                        fresh--;
                        flag = true;
                        vis[newRow][newCol] = 1;
                        q.push({newRow, newCol});
                    }
                }
            }

            if(flag == true) minutes++;
        }

        if(fresh!=0) return -1;

        return minutes;
    }
};