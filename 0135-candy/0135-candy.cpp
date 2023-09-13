class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> CandyArr(n,1);
        int TotalCandy = 0;
        
        //scan from left to right
        for(int i=0; i<n-1; i++){
            if(ratings[i] < ratings[i+1]){
                CandyArr[i+1] = CandyArr[i] + 1; 
            }
        }
        //Scan from right to left
        for(int i=n-1; i>0; i--){
            if( ratings[i-1] > ratings[i]){
                if(CandyArr[i-1] <= CandyArr[i])
                    CandyArr[i-1] = CandyArr[i] + 1;
            }
        }
            
        for(int i=0; i<n; i++){
            TotalCandy += CandyArr[i];
        }
        
        return TotalCandy;
    }
};