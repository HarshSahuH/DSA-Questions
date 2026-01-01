class Solution {
    public int findKRotation(int arr[]) {
        // Code here
        int n = arr.length;
        int pivotIndex = -1;
        
        for(int i=0; i<=n-2; i++){
            if(arr[i] > arr[i+1]){
                pivotIndex = i+1;
            }
        }
        
        if(pivotIndex == -1){
            return 0;
        }
        else{
            return pivotIndex;
        }
    }
}