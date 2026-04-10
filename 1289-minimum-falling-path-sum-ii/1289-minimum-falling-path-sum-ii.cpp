class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp = grid;

        for(int i = n-2; i >= 0; i--) {

            int min1 = INT_MAX, min2 = INT_MAX;
            int col1 = -1;
            for(int j = 0; j < n; j++) {
                if(dp[i+1][j] < min1) {
                    min2 = min1;
                    min1 = dp[i+1][j];
                    col1 = j;
                } else if(dp[i+1][j] < min2) {
                    min2 = dp[i+1][j];
                }
            }
            for(int j = 0; j < n; j++) {
                if(j == col1)
                    dp[i][j] = grid[i][j] + min2;
                else
                    dp[i][j] = grid[i][j] + min1;
            }
        }

        return *min_element(dp[0].begin(), dp[0].end());
    }
};