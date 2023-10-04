class Solution {
public:
    string removeDigit(string number, char digit) {
        int i = 1;
        for(; i<number.length(); i++){
            if(number[i-1] == digit){
                if(number[i] > number[i-1]){
                    return number.substr(0,i-1) + number.substr(i,number.length());
                }
            }
        }
        
        int lastindex = -1;
        for(int i=0; i<number.length(); i++){
            if(number[i] == digit){
                lastindex = i;
            }
        }
        return number.substr(0,lastindex)+number.substr(lastindex+1,number.length());
        
    }
};