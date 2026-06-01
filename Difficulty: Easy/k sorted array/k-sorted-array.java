// User function Template for Java

class Solution {
    static String isKSortedArray(int arr[], int n, int k) {
        // code here
        
        HashMap<Integer,Integer> map = new HashMap<>();
        int [] nums = new int[n];
        
        for(int i=0; i<arr.length; i++){
            nums[i] = arr[i]; 
        }
        
        Arrays.sort(nums);
        
        for(int i=0; i<n; i++){
            map.put(nums[i],i);
        }
        
        for(int i=0; i<arr.length; i++){
            int currentPos = i;
            int idealPos = map.get(arr[i]);
            
            int val = Math.abs(currentPos - idealPos);
            
            if(val <= k){
                continue;
            }
            else{
                return "No";
            }
        }
        
        return "Yes";
    }
}