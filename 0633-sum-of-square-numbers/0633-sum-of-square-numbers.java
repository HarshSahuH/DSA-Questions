class Solution {
    public boolean judgeSquareSum(int c) {
        if (c == 1) {
            return true;
        }
        long half = (long)Math.sqrt(c);
        long left = 0;
        long right = half;

        while (left <= right) {
            long sum = left * left + right * right;
            if (sum == c)
                return true;
            else if (sum < c)
                left++;
            else
                right--;
        }
        return false;
    }
}