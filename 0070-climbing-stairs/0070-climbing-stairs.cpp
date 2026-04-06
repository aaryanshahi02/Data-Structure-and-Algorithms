class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        if(n==1 || n==2 || n==3) return n;
        dp[n-1] = 1;
        dp[n-2] = 2;
        dp[n] = 0;

        for(int i = n - 3; i >= 0; i--) {
            dp[i] = dp[i + 1] + dp[i + 2];
        }

        return dp[0];
    }
};