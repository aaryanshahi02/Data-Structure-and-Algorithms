class Solution {
public:
    vector<int> dp;
    int minCost(int i, vector<int>& cost, vector<int> &dp){
        if(i >= cost.size()) return 0;
        if(dp[i] != -1) return dp[i];

        int fo = minCost(i+1, cost, dp);
        int so = minCost(i+2, cost, dp);

        return dp[i] = cost[i] + min(fo, so); 
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp.resize(n + 1, -1);
        return min(minCost(0, cost, dp), minCost(1, cost, dp));
    }
};