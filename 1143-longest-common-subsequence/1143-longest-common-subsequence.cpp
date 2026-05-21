class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                dp[n][j] = 0;
                dp[i][m] = 0;
            }
        }

        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                if(text1[i] == text2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }else{
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }

        return dp[0][0];
        // return solve(text1, text2, 0, 0, dp);
    }

    // int solve(string text1, string text2, int i, int j, vector<vector<int>> &dp){
    //     int n = text1.length();
    //     int m = text2.length();

    //     if(i >= n || j >= m) return 0;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int eq = 0;
    //     if(text1[i] == text2[j]){
    //         eq = 1 + solve(text1, text2, i + 1, j + 1, dp);
    //     }
    //     int noteq = max(solve(text1, text2, i+1, j, dp), solve(text1, text2, i, j+1, dp));

    //     return dp[i][j] = max(eq, noteq);
    // }

};