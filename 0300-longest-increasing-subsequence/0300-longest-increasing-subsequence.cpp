class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        vector<vector<int>> dp(arr.size() + 1, vector<int> (arr.size() + 1, -1));
        return solve(arr, 0, -1, dp);
    }

    int solve(vector<int> &arr, int i, int j, vector<vector<int>> &dp){
        int n = arr.size();
        if(i == n) return 0;

        if(dp[i][j+1] != -1) return dp[i][j+1];

        int notTake = solve(arr, i+1, j, dp);
        int take = 0;
        if(j == -1 || arr[i] > arr[j]){
            take = 1 + solve(arr, i+1, i, dp);
        }
        return dp[i][j+1] = max(notTake, take);
    }
};