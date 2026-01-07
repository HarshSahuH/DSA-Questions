class Solution {
    public int maxElement(int[] piles){
        int max = Integer.MIN_VALUE;
        for(int i : piles){
            if(i > max){
                max = i;
            }
        }
        return max;
    }
    public int calulateTime(int []piles, int mid){
        int totalTimeTaken = 0;
        for(int i : piles){
            totalTimeTaken += Math.ceil((double)i/(double)mid);
        }
        return totalTimeTaken;
    }
    public int minEatingSpeed(int[] piles, int h) {
       int low = 1;
       int high = maxElement(piles);
       int ans = 0;

       while(low <= high){
        int mid = low + (high-low)/2;
        int time = calulateTime(piles,mid);

        if(time <= h){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid+1;
        }
       }
       return ans;
    }
}