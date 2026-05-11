class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 1e9));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = n-1; i >= 0; i--) {
            for (int j = 1; j <= amount; j++) {
                int notPick = dp[i + 1][j];

                int pick = 1e9;
                if (coins[i] <= j) {
                    pick = 1 + dp[i][j - coins[i]];
                }

                dp[i][j] = min(pick, notPick);
            }
        }

        int result = dp[0][amount];
        return (result >= 1e9) ? -1 : result;
    }
};