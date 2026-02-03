class Solution {
    public int[] findPQ(int[] nums){
        int [] pq = new int[2];

        for(int i=1; i<=nums.length-2; i++){
            if(nums[i] > nums[i+1] && nums[i-1] < nums[i]){
                pq[0] = i;
                break;
            }
        }
        for(int i=1; i<=nums.length-2; i++){
            if(nums[i-1] > nums[i] && nums[i] < nums[i+1]){
                pq[1] = i;
                break;
            }
        }
        return pq;
    }
    public boolean isTrionic(int[] nums) {

        int[] ans = findPQ(nums);
        int p = ans[0];
        int q  = ans[1];
        int n = nums.length;

        if(p == -1 || q == -1) return false;
        if(!(0 < p && p < q && q < n-1)) return false;

        for(int i=0; i<p; i++){
            if(nums[i+1] > nums[i]){
                continue;
            }
            return false;
        }
        for(int i=p; i<q; i++){
            if(nums[i] > nums[i+1]){
                continue;
            }
            return false;
        }
        for(int i=q; i<n-1; i++){
             if(nums[i+1] > nums[i]){
                continue;
            }
            return false;
        }
        return true;
    }
}