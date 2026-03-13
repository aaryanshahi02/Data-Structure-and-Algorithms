class Solution {
    
    bool isValid(vector<int>& piles, int hours, int speed){
        long long time = 0;
        for(int i=0; i<piles.size(); i++){
            time += (piles[i] + speed - 1) / speed;
        }
        if(time<=hours) return true;
        
        return false;
    }
    
  public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = 0;
        
        for(int i=0; i<piles.size(); i++){
            end = max(piles[i], end);
        }
        int ans = 0;
        
        while(start<=end){
            int mid = start + (end-start)/2;
            
            if(isValid(piles, h, mid)){
                ans = mid;
                end = mid-1;
            }
            
            else{
                start = mid+1;
            }
        }
        return ans;
        
    }
};
        
