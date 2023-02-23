class Solution {
public:
//     
    vector<int> finalPrices(vector<int>& prices) {
        
        vector<int> discount;
        stack<int> s;
        
        for(int i=prices.size()-1; i>=0; i--){
            
            while (!s.empty() && s.top() > prices[i]) {
              s.pop();
            }
            
            if (s.empty()) {
              discount.push_back(prices[i]);
            } 
            
            else {
               discount.push_back(prices[i] - s.top());
            }
             
            s.push(prices[i]);
         }

        reverse(discount.begin(),discount.end());
        return discount;
    }
};