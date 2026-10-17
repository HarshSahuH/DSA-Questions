class Solution {
    // Helper class to store the number, its digit sum, and its original index
    static class Element implements Comparable<Element> {
        long val;
        int digitSum;
        int index;

        public Element(long val, int digitSum, int index) {
            this.val = val;
            this.digitSum = digitSum;
            this.index = index;
        }

        @Override
        public int compareTo(Element other) {
            if (this.digitSum != other.digitSum) {
                return Integer.compare(this.digitSum, other.digitSum);
            }
            return Long.compare(this.val, other.val);
        }
    }

    public int sumOfNumsDigit(long num) {
        int sum = 0;
        while (num != 0) {
            sum += (int) (num % 10);
            num /= 10;
        }
        return sum;
    }

    public int minSwaps(int[] nums) {
        int n = nums.length;
        Element[] elements = new Element[n];

        for (int i = 0; i < n; i++) {
            elements[i] = new Element(nums[i], sumOfNumsDigit(nums[i]), i);
        }

        // Sort based on digit sum, then by value
        Arrays.sort(elements);

        // Find the minimum swaps using cycle decomposition
        boolean[] visited = new boolean[n];
        int cycles = 0;

        for (int i = 0; i < n; i++) {
            // If element is already visited or already in the correct position
            if (visited[i] || elements[i].index == i) {
                continue;
            }

            // Traverse the cycle
            int cycleSize = 0;
            int curr = i;
            while (!visited[curr]) {
                visited[curr] = true;
                curr = elements[curr].index;
                cycleSize++;
            }

            if (cycleSize > 1) {
                cycles += (cycleSize - 1);
            }
        }

        return cycles;
    }
}