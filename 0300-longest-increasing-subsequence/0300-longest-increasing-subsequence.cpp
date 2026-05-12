class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        vector<vector<int>> dp(arr.size() + 1, vector<int> (arr.size() + 1, -1));
        int n = arr.size();
        for(int i=0; i<=n; i++){
            dp[n][i] = 0;
        }

        for(int i = n-1; i>=0; i--){
            for(int j=-1; j<=i-1; j++){
                int notTake = dp[i+1][j+1];

                int take = 0;
                if(j == -1 || arr[i] > arr[j]){
                    take = 1 + dp[i+1][i+1];
                }
                dp[i][j+1] = max(take, notTake);
            }
        }
        // return solve(arr, 0, -1, dp);
        return dp[0][0];
    }

    // int solve(vector<int> &arr, int i, int j, vector<vector<int>> &dp){
    //     int n = arr.size();
    //     if(i == n) return 0;

    //     if(dp[i][j+1] != -1) return dp[i][j+1];

    //     int notTake = solve(arr, i+1, j, dp);
    //     int take = 0;
    //     if(j == -1 || arr[i] > arr[j]){
    //         take = 1 + solve(arr, i+1, i, dp);
    //     }
    //     return dp[i][j+1] = max(notTake, take);
    // }
};