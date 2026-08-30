class Solution {
    public int countSpecialIntegers(int[] nums) {
        int n = nums.length;
        int count = 0;
        HashMap<Integer, Integer> map = new HashMap<>();

        map.put(nums[0], 1);
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != nums[i - 1]) {
                map.put(nums[i], map.getOrDefault(nums[i], 0) + 1);
            }
        }

        for (int block : map.values()) {
            if (block == 1) {
                count++;
            }
        }
        return count;
    }
}