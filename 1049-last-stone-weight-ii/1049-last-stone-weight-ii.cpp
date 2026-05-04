class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (int x : stones) sum += x;

        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;


        for (int stone : stones) {
            for (int j = target; j >= stone; j--) {
                
                dp[j] = dp[j] || dp[j - stone];
            }
        }

        for (int j = target; j >= 0; j--) {
            if (dp[j]) {
                return sum - 2 * j;
            }
        }

        return 0;
    }
};