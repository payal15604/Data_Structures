class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int profit = 0;
        for(auto x : prices)
        {
            if(x > buy){
                profit = max(profit, x - buy);
            } else {
                buy = x;
            }

        }

        return profit;
    
    }
};