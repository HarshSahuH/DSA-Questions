class Solution {
public:
    int maxProfit(vector<int>& prices) {
       
        int minSofar = prices[0];
        int maxProfit = 0;
        
        for(int i=0; i<prices.size(); i++){
            
            if(prices[i] < minSofar){
                minSofar = prices[i];
            }
            int profit = prices[i] - minSofar;
            maxProfit = max(profit , maxProfit);
        }
        return maxProfit;  
    } //T.C.O(N) , S.C.O(1) 
};

 /* Approach 1
   T.C.O(N^2) , S.C.O(1)  
   
        int profit = INT_MIN;
        for(int i=0; i<prices.size(); i++){
            for(int j=i+1; j<prices.size(); j++){
                int currProfit = prices[j] - prices[i];
                profit = max(currProfit, profit);
            }
        }
        if(profit<0)
            return 0;
        else
        return profit;
*/
    
    /* 
        this approach is not work on [2,4,1] 
        Approach 2 optimise T.C. O(N) S.C. O(1) 
        int buyPrice = INT_MAX;;
        int buyIndex = -1;
        int sellPrice = INT_MIN;
        int profit = 0;
        
        //find buy price 
        for(int i=0; i<prices.size(); i++){
            if(prices[i]<buyPrice){
                buyPrice = prices[i];
                buyIndex = i;
            }
        }
        
        //find sell price
        for(int i = buyIndex; i<prices.size(); i++){
            if(prices[i]>sellPrice){
                sellPrice = prices[i];
            }
        }
        
        profit = sellPrice - buyPrice;
        return profit;
     }*/