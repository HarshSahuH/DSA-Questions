class Solution {
public:
    int totalMoney(int n) {
        int totalM = 0;
        int monday = 1;
        
        while(n>0){
            for(int i=0; i <min(n,7); i++){
                totalM += monday + i;
            }
            n = n-7;
            monday++;
        }
        return totalM;
    }
};