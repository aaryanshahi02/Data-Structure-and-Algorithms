class Solution {
public:
    int rD[4] = {-1, 1, 0, 0};
    int cD[4] = {0,0,-1,1};

    bool isValid(int row, int col, int n){
        return (row >= 0 && row < n && col >=0 && col < n);
    }

    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int maxDist = 0;
        vector<vector<int>> ans(n, vector<int> (n, -1));
        queue<pair<int, int>> q;

        for(int i=0 ;i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        if(q.empty() || q.size() == n*n) return -1;

        while(!q.empty()){
            auto[cR, cC] = q.front();
            q.pop();

            for(int i=0; i<4; i++){
                int nR = cR + rD[i];
                int nC = cC + cD[i];

                if(isValid(nR, nC, n) && ans[nR][nC] == -1){
                    ans[nR][nC] = ans[cR][cC]+1;
                    maxDist = max(maxDist, ans[nR][nC]);
                    q.push({nR, nC});

                }
            }
        }
        return maxDist;
    }
};