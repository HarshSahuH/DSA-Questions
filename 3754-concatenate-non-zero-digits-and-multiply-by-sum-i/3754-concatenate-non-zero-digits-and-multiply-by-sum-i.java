class Solution {
    public long sumAndMultiply(int n) {
        if(n == 0) return 0;
        long x = 0;
        String stringNumber = "";

        while(n > 0){
            int digit = n%10;
            if(digit != 0){
                stringNumber = stringNumber + String.valueOf(digit);
            }
            n = n/10;
        } 

        String reverseString = new StringBuilder(stringNumber).reverse().toString();

        long number = Long.parseLong(reverseString);

        long temp = number;
        long sum = 0;
        while(temp > 0){
            long digit = temp % 10;
            sum = sum + digit;
            temp = temp / 10;
        }

        return number*sum;
    }
}