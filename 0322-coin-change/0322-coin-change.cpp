class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        
        int result = func(coins, amount, n, dp);
        
        return (result >= 1e9) ? -1 : result;
    }

    int func(vector<int>& coins, int amount, int n, vector<vector<int>>& dp) {
        if (amount == 0) return 0;
        if (n == 0 || amount < 0) return 1e9;
        
        if (dp[n][amount] != -1) return dp[n][amount];

        int notPick = func(coins, amount, n - 1, dp);
        int pick = 1 + func(coins, amount - coins[n - 1], n, dp);

        return dp[n][amount] = min(pick, notPick);
    }
};