class Solution {
    bool isValid(vector<int>& weights, int days, int capacity){
        int day = 1;
        int load = 0;

        for(int w:weights){
            if(load+w > capacity){
                day++;
                load = w;
            }else{
                load += w;
            }
        }
        return day <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int s = 0;
        int e = 0;

        for(int w:weights){
            s = max(s, w);
            e += w;
        }

        int ans = e;

        while(s <= e){
            int mid = s+(e-s)/2;

            if(isValid(weights, days, mid)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
};