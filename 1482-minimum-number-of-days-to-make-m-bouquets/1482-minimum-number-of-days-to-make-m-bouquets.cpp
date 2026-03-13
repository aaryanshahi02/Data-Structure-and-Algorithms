class Solution {
     bool canMake(vector<int>& bloomDay, int k, int m, int day){
        int count = 0;
        int bouquets = 0;
        
        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= day){
                count++;
                if(count == k){
                    bouquets++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }
        
        return bouquets >= m;
    }
    
  public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int low = INT_MAX;
        int high = INT_MIN;
        int ans = 0;
        
        if((long long)m * k > bloomDay.size()) return -1;
        
        for(int i=0; i<bloomDay.size(); i++){
            low = min(low, bloomDay[i]);
            high = max(high, bloomDay[i]);
        }
        
        while(low <= high){
            int mid = low + (high-low)/2;
            
            if(canMake(bloomDay, k, m, mid)){
                ans = mid;
                high = mid - 1;
            } 
            else{
                low = mid + 1;
            }
        }
        
        return ans;
            
        
        
        
    }
};