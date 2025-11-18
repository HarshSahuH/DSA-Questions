// import java.util.*;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] ans = new int[2];

        Map<Integer,Integer> helper = new HashMap<>();

        for(int i=0; i<nums.length; i++){
            if(helper.containsKey(target-nums[i])){
                ans[0]=helper.get(target-nums[i]);
                ans[1]=i;
            }else{
                helper.put(nums[i],i);
            }
        }
        return ans;
    }
}