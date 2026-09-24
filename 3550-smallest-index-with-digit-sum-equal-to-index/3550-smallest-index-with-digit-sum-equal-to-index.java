class Solution {
    public int sumOfDigit(int num){
        int sum = 0;

        while(num !=0){
            int digit = num%10;
            sum += digit;
            num = num / 10;
        }

        return sum;
    }
    public int smallestIndex(int[] nums) {
       for(int i=0; i<nums.length; i++){
        if(i == sumOfDigit(nums[i])){
            return i;
        }
       } 
       return -1;
    }
}