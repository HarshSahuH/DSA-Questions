class Solution {
    public int minPlatform(int arr[], int dep[]) {
        //  code here
        Arrays.sort(arr);
        Arrays.sort(dep);
        
        int n = arr.length;
        int i=0; // arival time 
        int j=0; // depature time 
        int result = 0;
        int platformNeeded =0;
        
        while(i < n && j< n){
            if(arr[i] <= dep[j]){
                 // If next train arrives before current one departs
                platformNeeded++;
                i++;
            }
            else{
                // One train departs, platform freed dep[j] < arr[i]
                platformNeeded--;
                j++;
            }
            if(platformNeeded > result){
                result = platformNeeded;
            }
        }
      return result;    
    }
}
