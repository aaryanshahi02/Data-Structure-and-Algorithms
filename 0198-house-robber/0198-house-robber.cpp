class Solution {
public:

    vector<int> dp;

    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n + 1, -1);
        return houseRob(nums, n);
    }

    int houseRob(vector<int>& nums, int n){
        

        if (n==0) return 0;
        if (n==1) return nums[0];

        if(dp[n] != -1) return dp[n];

        int rob = nums[n-1] + houseRob(nums, n-2);
        int not_rob = 0 + houseRob(nums, n-1);

        return dp[n] = max(rob, not_rob);
    }
};