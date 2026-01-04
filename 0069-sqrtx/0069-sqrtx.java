class Solution {
    public int mySqrt(int x) {
        if(x==1 || x == 0) return x;

        int low =1;
        int high = x/2;
        int possibleAns = 1;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(mid <= x/mid){  // if ((long) mid * mid <= x)
                possibleAns = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return possibleAns;
    }
}