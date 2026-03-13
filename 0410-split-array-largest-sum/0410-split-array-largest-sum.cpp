class Solution {
    bool isValid(vector<int>& nums, int k, int capacity){
        int dayCount = 1;
        int load = 0;

        for(int w:nums){
            if(load+w > capacity){
                dayCount++;
                load = w;
            }else{
                load += w;
            }
        }
        return dayCount <= k;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int low = 0;
        int high = 0;

        for(int w:nums){
            low = max(low, w);
            high += w;
        }

        int ans = high;

        while(low <= high){
            int mid = low+(high-low)/2;

            if(isValid(nums, k, mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};