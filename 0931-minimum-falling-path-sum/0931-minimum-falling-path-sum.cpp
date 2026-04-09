class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& triangle) {
        
        int n = triangle.size();

        vector<vector<int>> dp = triangle;

        for(int i = n-2; i >= 0; i--){
            for(int j = 0; j < triangle[i].size(); j++){
                int left = INT_MAX;
                if(j > 0) left = dp[i+1][j-1];
                int right = INT_MAX;
                if(j < n-1) right = dp[i+1][j+1];
                int down = dp[i+1][j];
                int next = min(left, right);
                dp[i][j] = triangle[i][j] + min(next, down);
            }
        }
        
        return *min_element(dp[0].begin(), dp[0].end());
    }
};