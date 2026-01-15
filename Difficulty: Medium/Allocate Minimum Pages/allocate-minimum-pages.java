class Solution {
    public int possible(int mid, int [] arr, int k, int n){
        int student = 1;
        int pagesAllocated = 0;
        
        for(int i=0; i<n; i++){
            if(arr[i] + pagesAllocated <= mid){
                pagesAllocated += arr[i];
            }
            else{
                student++;
                pagesAllocated = arr[i];
            }
        }
        return student;
    }
    public int findPages(int[] arr, int k) {
        // code here
        int n = arr.length;
        int low = Integer.MIN_VALUE;
        int high = 0;
        int ans = -1;
        int cntStudent = 0;
        
        if (k > n) return -1;
        
        for(int i=0; i<n; i++){
            low = Math.max(low,arr[i]);
            high += arr[i]; 
        }
        
        while(low <= high){
            int mid = low + (high-low)/2;
            cntStudent = possible(mid,arr,k,n);
            
            if(cntStudent <= k){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
}