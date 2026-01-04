class Solution {
    
    public boolean checkFourDivisorOrNot(int n){
        int count = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                count += (i * i == n) ? 1 : 2;
                if (count > 4) return false; // early exit
            }
        }
        return count == 4;
    }

    public int findFourDivisorSum(int n){
        int divisorSum = 1 + n;
        int i = 2;
        while(i<n){
            if(n%i == 0){
                divisorSum += i;
            }
            i++;
        }
        return divisorSum;
    }

    public int sumFourDivisors(int[] nums) {
        int ans = 0; 
        int n = nums.length;

        for(int i=0; i<n; i++){
            if(checkFourDivisorOrNot(nums[i])){
                ans += findFourDivisorSum(nums[i]);
            }
        }
        return ans;
    }
}