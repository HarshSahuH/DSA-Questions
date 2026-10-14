class Solution {
    public String maxSumOfSquares(int num, int sum) {
        StringBuilder number = new StringBuilder();

        if(num == 1 && sum >9){
            return "";
        }

        while(sum != 0){
            if(sum <= 9){
                number.append(sum);
                sum = 0;
            }else{
                number.append(9);
                sum = sum - 9;
            }
        }

        if(number.length() < num && sum == 0){
            while(number.length() != num){
                number.append(0);
            }
        }
        
        return  number.length() == num ? number.toString() : "";
    }
}