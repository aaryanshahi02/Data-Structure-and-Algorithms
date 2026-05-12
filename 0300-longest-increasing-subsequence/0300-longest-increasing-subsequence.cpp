class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        

        for(int i=1; i<nums.size(); i++){
            for(int j=i-1; j>=0; j--){

                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
                
            }
        }
        int maxi = INT_MIN;
        for(int x : dp){
            
                maxi = max(maxi, x);
        }
        return maxi;
    }
};