class Solution {
    public int[] findErrorNums(int[] nums) {
        int duplicate = -1;
        int missing = -1;
        int ans[] = new int[2];

        int n = nums.length;
        HashMap<Integer, Integer> freq = new HashMap<>();

        for (int i = 0; i < n; i++) {
            freq.put(nums[i], freq.getOrDefault(nums[i], 0) + 1);
        }

        for (Map.Entry<Integer, Integer> entry : freq.entrySet()) {
            if (entry.getValue() > 1) {
                duplicate = entry.getKey();
                break; // Found the duplicate, no need to keep checking
            }
        }

        for (int i = 1; i <= n; i++) {
            if (!freq.containsKey(i)) {
                missing = i;
                break;
            }
        }
        ans[0] = duplicate;
        ans[1] = missing;

        return ans;
    }
}