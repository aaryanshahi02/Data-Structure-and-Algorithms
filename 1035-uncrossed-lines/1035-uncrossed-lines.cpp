class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));

        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                dp[n][j] = 0;
                dp[i][m] = 0;
            }
        }

        for(int i = n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                
                if(nums1[i] == nums2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};