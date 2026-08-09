class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int total = 0;
        for(int num:nums){
            total += num;
        }
        if (total % 2 != 0) return false;
        int target = total/2;

        vector<vector<int>> dp(n, vector<int> (target+1, -1));
        return solve(nums, target, 0, dp);
    }

    bool solve(vector<int> &nums, int target, int i, vector<vector<int>> &dp){
        if(target == 0) return true;
        if(i == nums.size()) return false;

        if(dp[i][target] != -1) return dp[i][target];

        bool take = false;
        if(nums[i] <= target){
            take = solve(nums, target-nums[i], i+1, dp);
        }

        bool notTake = solve(nums, target, i+1, dp);

        return dp[i][target] = take || notTake;
    }
};