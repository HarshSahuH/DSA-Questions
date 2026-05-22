class Solution {
    public int[] sortArray(int[] nums) {
        int n = nums.length;
        
        // 1. Build the Max-Heap
        buildHeap(nums, n);
        
        // 2. Extract elements one by one from the heap
        for (int i = n - 1; i >= 0; i--) {
            // Move current root (largest element) to the end of the array
            swap(nums, 0, i);
            
            // Call max heapify on the reduced heap
            heapify(nums, i, 0);
        }
        
        // Return the now sorted array
        return nums;
    }
    
    // Heapify function to maintain max-heap property.
    private void heapify(int arr[], int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if (left < n && arr[left] > arr[largest])
            largest = left;
            
        if (right < n && arr[right] > arr[largest])
            largest = right;
            
        if (largest != i) {
            swap(arr, i, largest);
            heapify(arr, n, largest);
        }
    }

    // Function to build a Heap from array.
    private void buildHeap(int arr[], int n) { 
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
    }
    
    // Java Swap Helper Method
    private void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}