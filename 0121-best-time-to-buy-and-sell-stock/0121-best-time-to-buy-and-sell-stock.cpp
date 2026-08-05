class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int profit = 0;

        for(int price:prices){
            int cost = price - mini;
            profit = max(profit, cost);
            mini = min(price, mini);
        }
        return profit;
    }
};