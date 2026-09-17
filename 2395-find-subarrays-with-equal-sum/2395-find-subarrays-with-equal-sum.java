class Solution {
    public boolean findSubarrays(int[] nums) {
        Set<Integer> s = new HashSet<>();
        int n = nums.length;

        for(int i=1; i<n; i++){
            int element1 = nums[i];
            int element2 = nums[i-1];

            if(s.contains(element1 + element2)){
                return true;
            }else{
                s.add(element1+element2);
            }
        }
        return false;
    }
}