class Solution {
    public void swap(int [] arr, int a, int b){
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
    
    
    public void heapify(int arr[], int n, int i){
        
        int largest = i;
        int leftChild = i*2+1;
        int rightChild = i*2+2;
        
        if(leftChild < n && arr[leftChild] > arr[largest]){
            largest = leftChild;
        }
        
        if(rightChild < n && arr[rightChild] > arr[largest]){
            largest = rightChild;
        }
        
        if(largest != i){
           swap(arr,largest,i);
           heapify(arr,n, largest); 
        }
    }
    
    
    public void buildHeap(int arr[], int n){
        int startIdx = (n/2)-1;
        
        for(int i = startIdx; i>=0; i--){
            heapify(arr,n,i);
        }
    }
    
    public void heapSort(int arr[]) {
        int n = arr.length;
        buildHeap(arr,n);
        
        
        for(int i=n-1; i> 0; i--)
        {
            swap(arr,i,0);
            heapify(arr,i,0);
        }
    }
}