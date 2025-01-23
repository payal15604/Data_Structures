class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l= 0, r = 0; 
        int max_profit = 0;

        while(r < prices.size())
        {
            if(prices[l] < prices[r])
            {
                max_profit = max(prices[r] - prices[l], max_profit);
            }

            else
            {
                l = r;
            }

            r++;
        }

        return max_profit;

    }
};