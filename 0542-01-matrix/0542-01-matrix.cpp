class Solution {
public:
    int rowDir[4] = {0,0,-1,1};
    int colDir[4] = {-1,1,0,0};

    bool isValid(int row, int col, int n, int m){
        return (row >= 0 && row < n && col >= 0 && col < m);
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> ans(n, vector<int>(m, -1));
        queue<pair<int, int>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            auto[currRow, currCol] = q.front();
            q.pop();

            for(int i=0; i<4; i++){
                int newRow = currRow + rowDir[i];
                int newCol = currCol + colDir[i];

                if(isValid(newRow, newCol, n, m) && ans[newRow][newCol] == -1){
                    ans[newRow][newCol] = ans[currRow][currCol] + 1;
                    q.push({newRow, newCol});
                }
            }
        }
        return ans;
    }
};