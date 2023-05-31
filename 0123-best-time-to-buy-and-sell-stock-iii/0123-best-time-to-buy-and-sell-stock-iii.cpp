class Solution {
public:
    int maxProfit(vector<int>& prices) {
       
        int n = prices.size();
        int *profitArr = new int[n];
        for(int i=0; i<n; i++){
            profitArr[i]=0;
        }
        
        //step 1 work on second trancation B->S  
        int max_sell_price = prices[n-1];
        for(int i=n-2; i>=0; i--)
        {
            if(prices[i] > max_sell_price)
            {
             max_sell_price = prices[i];   
            }
            
            int curr_profit = max_sell_price - prices[i];
            profitArr[i] = max( curr_profit , profitArr[i+1] );
        }
        
        // step 2 work for first trancation
        int min_buy_price = prices[0];
        for(int i=1; i<n; i++){
            
            if(prices[i] < min_buy_price){
                min_buy_price = prices[i];
            }
            int curr_profit = profitArr[i] + (prices[i] - min_buy_price) ;
            profitArr[i] = max( profitArr[i-1] , curr_profit );
        }
        
        int result = profitArr[n-1];
        delete[] profitArr;
        
        return result;
    }
};

//T.C. O(N+N) = O(2N) = O(N)  S.C. O(N)  