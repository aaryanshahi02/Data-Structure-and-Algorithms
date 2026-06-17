class Solution {
public:
    int solve(int i, vector<int> &nums, vector<int> &dp){
        int n = nums.size();
        int ans = 1e9;

        if(i >= n-1) return 0;

        if(dp[i] != -1) return dp[i];

        for(int j=1; j<=nums[i]; j++){
            ans = min(ans, 1+solve(i+j, nums, dp));
        }
        return dp[i] = ans;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(0, nums, dp);
    }
};