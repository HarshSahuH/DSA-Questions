import java.util.HashMap;

class Solution {
    public int countSpecialIntegers(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();

        // Step 1: Map mein pehla element dalo (put)
        map.put(nums[0], 1);

        // Step 2: Continuous blocks count karo
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != nums[i - 1]) {
                map.put(nums[i], map.getOrDefault(nums[i], 0) + 1);
            }
        }

        // Step 3: Block values par iterate karo (values)
        int count = 0;
        for (int block : map.values()) {
            if (block == 1) {
                count++;
            }
        }

        return count;
    }
}