class Solution {
    public boolean isMaxHeap(int[] arr) {
        // code here
        int n = arr.length;
        
        for(int i=0; i<=(n-2)/2; i++){
            //left chird
            if(arr[2*i+1] > arr[i]){
                return false;
            }
            
            //right child 
            if(2*i+2 <n && arr[2*i+2] > arr[i]){
                return false;
            }
        }
         return true;
    }
}