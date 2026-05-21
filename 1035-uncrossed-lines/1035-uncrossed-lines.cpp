class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return solve(nums1, nums2, 0, 0, dp);
    }

    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j, vector<vector<int>> &dp){
        int n = nums1.size();
        int m = nums2.size();

        if(i == n || j == m) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int eq = 0;
        int noteq = 0;
        if(nums1[i] == nums2[j]){
            eq = 1 + solve(nums1, nums2, i+1, j+1, dp);
        }else{
            noteq = max(solve(nums1, nums2, i+1, j, dp), solve(nums1, nums2, i, j+1, dp));
        }

        return dp[i][j] = max(eq, noteq);
    }
};


