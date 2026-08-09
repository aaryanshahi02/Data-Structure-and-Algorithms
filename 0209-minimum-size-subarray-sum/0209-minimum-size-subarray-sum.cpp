class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int maxi = INT_MAX;

        for(int right=0; right<nums.size(); right++){
            sum+=nums[right];

            while(sum >= target){
                maxi = min(maxi, right-left+1);
                sum-=nums[left];
                left++;
            }
        }
        return maxi == INT_MAX ? 0 : maxi;
    }
};