class Solution {
public:
    vector<int> dp;
    
    int solve(int target) {
        if(dp[target] != -1) return dp[target];
        
        int k = 1;
        while((1 << k) - 1 < target) k++;
        
        if((1 << k) - 1 == target)
            return dp[target] = k;
        
        int res = k + 1 + solve((1 << k) - 1 - target);

        for(int m = 0; m < k-1; m++) {
            int dist = (1 << (k-1)) - 1 - ((1 << m) - 1);
            res = min(res, (k-1) + 1 + m + 1 + solve(target - dist));
        }
        
        return dp[target] = res;
    }
    
    int racecar(int target) {
        dp.assign(target + 1, -1);
        return solve(target);
    }
};