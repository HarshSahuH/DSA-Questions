class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0; 
        int minSofar = prices[0];
        
        for(int i = 0; i<prices.size(); i++){
            if(prices[i] < minSofar){ 
                minSofar = prices[i];
            }
            int currProfit = prices[i] - minSofar;
            profit = max(currProfit,profit);
        }
        return profit;
    }
    
};