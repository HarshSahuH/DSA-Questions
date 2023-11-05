class Solution {

public:
    int getWinner(vector<int>& arr, int k) {
         
        int winner = arr[0];
        int winCount = 0;
        
        for(int i=1; i<arr.size(); i++){
            if(winner > arr[i]){
                winCount++;
            }
            else{
                winner = arr[i];
                winCount = 1;
            }
            if(winCount == k){
                return winner;
            }
        }
         return winner;
    }
};