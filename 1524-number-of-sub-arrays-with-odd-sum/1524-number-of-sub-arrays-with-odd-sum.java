class Solution {
    final int mod = (int) 1e9 + 7;

    public int numOfSubarrays(int[] arr) {

        int result = 0;
        int countOdd = 0;
        int countEven = 1;
        int n = arr.length;

        long prefixSum[] = new long[n];
        prefixSum[0] = arr[0];
        long sum = 0;
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + arr[i];
        }

        for (int i = 0; i < n; i++) {
            if (prefixSum[i] % 2 == 0) {
                result = (result + countOdd) % mod;
                countEven++;
            } else {
                result = (result + countEven) % mod;
                countOdd++;
            }
        }

        return result;
    }
}