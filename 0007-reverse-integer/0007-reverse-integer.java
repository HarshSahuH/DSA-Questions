class Solution {
    public int reverse(int x) {
        if(x > Integer.MAX_VALUE || x < Integer.MIN_VALUE)
            return 0;
        
        int copyOfX = x; 
        int ans = 0;
        int extra = 0;

        if(copyOfX < 0 && copyOfX > Integer.MIN_VALUE){
            copyOfX *= -1; 

            while(copyOfX > 0){
                int digit = copyOfX % 10;
                 if (ans > Integer.MAX_VALUE / 10 || (ans == Integer.MAX_VALUE / 10 && digit > 7)) {
                return 0;
            }
            if (ans < Integer.MIN_VALUE / 10 || (ans == Integer.MIN_VALUE / 10 && digit < -8)) {
                return 0;
            }
                ans = ans * 10 + digit;
                copyOfX /= 10;
            }
            ans *= -1;
        }
        else{
            while(copyOfX > 0){
                int digit = copyOfX % 10;
                 if (ans > Integer.MAX_VALUE / 10 || (ans == Integer.MAX_VALUE / 10 && digit > 7)) {
                return 0;
            }
            if (ans < Integer.MIN_VALUE / 10 || (ans == Integer.MIN_VALUE / 10 && digit < -8)) {
                return 0;
            }
                ans = ans * 10 + digit;
                copyOfX /= 10;
            }
        }
        return ans;
    }
}