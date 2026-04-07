class Solution {
public:
    int solve(vector<int>& nums, int start, int end) {
        vector<int> dp(end + 3, 0);

        for(int i = end; i >= start; i--) {
            dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
        }

        return dp[start];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        int case1 = solve(nums, 0, n - 2);
        
        int case2 = solve(nums, 1, n - 1);

        return max(case1, case2);
    }
};