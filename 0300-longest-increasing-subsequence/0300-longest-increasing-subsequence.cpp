class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        return solve(0, -1, nums, dp);
    }

    int solve(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
        if(i == nums.size()) return 0;
        if(dp[i][j+1] != -1) return dp[i][j+1];

        int take = 0;
        if(j == -1 || nums[i] > nums[j]){
            take = 1 + solve(i + 1, i, nums, dp);
        }

        int notTake = solve(i+1, j, nums, dp);

        return dp[i][j+1] = max(take, notTake);
    }
};