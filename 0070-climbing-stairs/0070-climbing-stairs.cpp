class Solution {
public:
    vector<int> dp;
    int climbStairs(int n){
        dp.resize(n + 1, -1);
        return solve(0, n);
    }

    int solve(int i, int n) {
        if(i == n) return 1;
        if(i > n) return 0;
        if(dp[i] != -1) return dp[i];
        int fo = solve(i+1, n);
        int so = solve(i + 2, n);
        // int to = solve(i+3, n);




        return dp[i] = fo + so;
    }
};