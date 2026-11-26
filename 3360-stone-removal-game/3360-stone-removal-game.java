class Solution {
    public boolean canAliceWin(int n) {
        int chance = 10;
        boolean whosturn = true; // true means alice turn
        int remaining = n;

        while(remaining >= chance){
            remaining = remaining - chance;
            chance = chance - 1;
            whosturn = !whosturn; 
        }
        
       //// Alice wins if it is currently Bob's turn (!whosturn).
        return !whosturn;
        
    }
}