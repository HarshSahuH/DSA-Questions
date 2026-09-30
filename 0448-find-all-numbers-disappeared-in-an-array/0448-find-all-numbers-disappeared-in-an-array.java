class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> ans = new ArrayList<>();
        int n = nums.length;

        for(int i=0; i<n; i++){
            // Get the target index for the current number
            int index = Math.abs(nums[i])-1;

            // Negate the value sitting at that index if it isn't already negative
            if(nums[index] > 0){
                nums[index] = -nums[index];
            }
        }

        for(int i=0; i<n; i++){
            if(nums[i] > 0){
                ans.add(i+1);
            }
        }

        return ans;
    }
}