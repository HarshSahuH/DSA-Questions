class Solution {
    public int minSumOfLengths(int[] arr, int target) {
        int n = arr.length; 
        int i=0;
        int j=0;
        int currSum = 0;
        int [] minLenTillIdx = new int[n];
        Arrays.fill(minLenTillIdx,Integer.MAX_VALUE);
        int result = Integer.MAX_VALUE;
        int bestMin = Integer.MAX_VALUE;

        while(j<n){
            currSum += arr[j];

            // 2. Shrink window while sum exceeds target
            while(i<j && currSum > target){
                currSum -= arr[i++];
            }

            if(currSum == target){
               int length = j-i+1;

               // Check if there is a valid non-overlapping subarray before index i 
               if(i>0 && minLenTillIdx[i-1] != Integer.MAX_VALUE){
                    result = Math.min(result, length + minLenTillIdx[i-1]);
               }

               bestMin = Math.min(bestMin, length);
            }
            // Store the minimum length of subarray found so far up to index j
            minLenTillIdx[j] = bestMin; 
            j++;
        }

        return result == Integer.MAX_VALUE ? -1 : result;
    }
}