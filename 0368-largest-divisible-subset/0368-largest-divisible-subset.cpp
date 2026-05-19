class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> parent(n, -1);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }

        int maxVal = 1;
        int curr = 0;


        for(int i = 1; i < n; i++){
            for(int j = i-1; j >= 0; j--){
                if(nums[i] % nums[j]  == 0){
                    if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                }
            }

            if(dp[i] > maxVal){
                maxVal = dp[i];
                curr = i;
            }
        }

        vector<int> ans;
        while(parent[curr] != curr){
            // print num[curr];
            ans.push_back(nums[curr]);
            curr = parent[curr];

            // curr = parent[curr]
        }
        ans.push_back(nums[curr]);

        reverse(ans.begin(), ans.end());

        return ans;

    }
};