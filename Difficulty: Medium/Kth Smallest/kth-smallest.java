class Solution {
    public int kthSmallest(int[] arr, int k) {
        // Code here
        PriorityQueue<Integer> mxHeap = new PriorityQueue<>(Collections.reverseOrder());
        
        for(int i=0; i<arr.length; i++){
            mxHeap.add(arr[i]);
            
            if(mxHeap.size() > k){
                mxHeap.poll();
            }
            
        }
        return mxHeap.peek();
    }
}
