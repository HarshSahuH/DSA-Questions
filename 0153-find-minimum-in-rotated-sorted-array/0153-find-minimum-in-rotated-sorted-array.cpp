class Solution {
     int findKRotation(vector<int> arr, int n) {
	 int low = 0; 
	 int high = n-1;
	 
	 while(low <= high){
	     if(arr[low] <= arr[high]) return low;
	     
	     int mid = low+(high-low)/2;
	
	     int prev = (mid+n-1)%n;
	     int next = (mid+1)%n;
	     
	     if(arr[mid] <= arr[next] && arr[mid] <= arr[prev]){
	         return mid;
	     }
	     
	     else if(arr[low] <= arr[mid]){
	         low = mid+1;
	     }
	     else if(arr[mid] <= arr[high]){
	         high = mid - 1;
	     }
	 }
	 return 0;   
	}
public:
    int findMin(vector<int>& nums) {
        
        int index_of_min_element = findKRotation(nums,nums.size());
        
        return nums[index_of_min_element]; 
    }
};
/*
T.C. o(log n)
S.C. O(1)
Aditya verma method */