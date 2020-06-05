class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int profit = 0;
        int buyIdx = -1;
        
        for(size_t i=0; i<prices.size(); i++)
        {
            size_t nx = i + 1;
            
            if(nx == (prices.size()))
            {
                if(buyIdx != -1 && prices[i] > prices[buyIdx])            
                    profit += (prices[i] - prices[buyIdx]);
                break;
            }
            
            if(prices[nx] > prices[i])
            {
                if(buyIdx == -1)
                    buyIdx = i; // buy
            }
            else if(prices[nx] < prices[i])
            {
                if(buyIdx != -1)
                {
                    profit += (prices[i] - prices[buyIdx]);
                    buyIdx = -1; // sell
                }
            }
        }
        
        return profit;
    }
};
