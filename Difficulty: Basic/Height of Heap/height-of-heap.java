class Solution {
    static int heapHeight(int n, int arr[]) {
        // code here
        // height og heap = logn with base 2
        if(n==1) return 1;
        
        int hight = (int)((Math.log(n)/Math.log(2))); 
         
        return hight;
    }
}