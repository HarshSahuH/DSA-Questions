class Solution {
    public double fractionalKnapsack(int[] val, int[] wt, int capacity) {
        // code here
        double profit=0.0;
        double currCapacity = capacity;
        int n = val.length;
        
        double[][] profitByWt = new double[n][2]; 
        
        for(int i=0; i<n; i++){
            profitByWt[i][0] = (double)val[i] / wt[i]; //calculate ratio
            profitByWt[i][1] = i; // store index
        }
        // Sort the pairs in descending order based on the profit/weight ratio
        Arrays.sort(profitByWt, (a,b)-> Double.compare(b[0],a[0]));
        
        for(int i=0; i< profitByWt.length; i++){
            if(currCapacity == 0) {
                // Knapsack is completely full
                break;
            } 
            int itemIndex = (int)profitByWt[i][1];
            
            if(wt[itemIndex]  <= currCapacity ){
                // Take the whole object
                profit += val[itemIndex];
                currCapacity -= wt[itemIndex];
            }
            else{
                // Take the fraction of the object that fits
                double fractionalVal = (double)currCapacity/wt[itemIndex] ; 
                profit +=  (val[itemIndex]*fractionalVal);
                currCapacity = 0;
            }
        }
        
        return profit;
    }
}