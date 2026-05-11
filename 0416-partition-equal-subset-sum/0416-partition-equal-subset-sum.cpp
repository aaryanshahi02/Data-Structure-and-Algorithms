class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int x : nums) total+=x;

        if(total % 2 != 0) return false;

        int target = total / 2;
        vector<vector<bool>> dp(nums.size() + 1, vector<bool> (target+1, false));
        // vector<vector<bool>> vis(nums.size() + 1, vector<bool> (target+1, false));

        for(int i=0; i<=nums.size(); i++){
            dp[i][0] = true;
        }
        int n = nums.size();

        for(int i = n-1; i>=0; i--){
            for(int j=1; j<=target; j++){
                bool notTake = dp[i+1][j];

                bool take = false;
                if(nums[i] <= j){
                    take = dp[i+1][j-nums[i]];
                }
                dp[i][j] = take || notTake;
            }
        }
        return dp[0][target];


        // return solve(target, 0, nums, dp, vis);
    }

    // bool solve(int target, int i, vector<int> &nums, vector<vector<bool>> &dp, vector<vector<bool>> &vis){
    //     if(target == 0) return true;
    //     if(i == nums.size()) return false;

    //     if(vis[i][target]) return dp[i][target];

    //     bool notTake = solve(target, i+1, nums, dp, vis);

    //     bool take = false;
    //     if(nums[i] <= target){
    //         take = solve(target-nums[i], i+1, nums, dp, vis);
    //     }
    //     vis[i][target] = true;
    //     return dp[i][target] = take || notTake;
    // }
};