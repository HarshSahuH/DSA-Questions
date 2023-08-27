class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        
        int Left=0,Right=0,UnderScore=0; 
        
        for(int i=0; i<moves.length(); i++){
            if(moves[i] =='L') Left++;
            else if(moves[i] == 'R') Right++;
            else UnderScore++;       
        }
         
           return  UnderScore + abs(Left - Right);
        }
};