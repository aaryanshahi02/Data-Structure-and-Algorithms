class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& triangle, vector<vector<long>>& dp) {
        int n = triangle.size();

        if(i == n - 1) return triangle[i][j];

        if(dp[i][j] != INT_MAX) return dp[i][j];

        int left = solve(i + 1, j, triangle, dp);
        int right = solve(i + 1, j + 1, triangle, dp);

        return dp[i][j] = triangle[i][j] + min(left, right);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<long>> dp(n, vector<long>(n, INT_MAX));

        return solve(0, 0, triangle, dp);
    }
};