class Solution {
    public boolean isPalindrome(int x) {
        
        int copyOfX = x;
        int reverseOfX = 0;

        while(copyOfX > 0){
            int digit = copyOfX % 10;
            reverseOfX = reverseOfX * 10 + digit;
            copyOfX /= 10;
        }
        if(x == reverseOfX){
            return true; 
            }
        else{
            return false;
        }
    }
}