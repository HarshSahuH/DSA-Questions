class Solution {
    public int jump(int[] nums) {
        int n = nums.length;
        if(n <= 1) return 0; // base case if we are already at last index

        int jumps = 0;
        int left = 0;
        int right = 0;
        int farthest = 0; 

        // Stop as soon as right reaches or exceeds the last index
        while(right < n-1){
            // Find the farthest index reachable from the current level [left, right]
            for(int i = left; i<=right; i++){
                farthest = Math.max(farthest, i+nums[i]);
            }
            // Move to the next level/window
            left = right+1;
            right = farthest;
            jumps = jumps + 1;
        }
        return jumps;
    }
}
// T.C. O(N)
// S.C. O(1)
