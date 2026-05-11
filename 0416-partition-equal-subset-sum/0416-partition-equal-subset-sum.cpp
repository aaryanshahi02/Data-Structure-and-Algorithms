class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int x : nums) total+=x;

        if(total % 2 != 0) return false;

        int target = total / 2;
        vector<vector<bool>> dp(nums.size() + 1, vector<bool> (target+1, false));
        vector<vector<bool>> vis(nums.size() + 1, vector<bool> (target+1, false));


        return solve(target, 0, nums, dp, vis);
    }

    bool solve(int target, int i, vector<int> &nums, vector<vector<bool>> &dp, vector<vector<bool>> &vis){
        if(target == 0) return true;
        if(i == nums.size()) return false;

        if(vis[i][target]) return dp[i][target];

        bool notTake = solve(target, i+1, nums, dp, vis);

        bool take = false;
        if(nums[i] <= target){
            take = solve(target-nums[i], i+1, nums, dp, vis);
        }
        vis[i][target] = true;
        return dp[i][target] = take || notTake;
    }
};