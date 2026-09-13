class Solution {
    public boolean canMakeArithmeticProgression(int[] arr) {
        Arrays.sort(arr);
        int n = arr.length;

        int d = Math.abs(arr[0] - arr[1]);

        for(int i=0; i<=n-2; i++){
            if(arr[i+1] - arr[i] != d){
                return false;
            }
        }
        return true;
    }
}