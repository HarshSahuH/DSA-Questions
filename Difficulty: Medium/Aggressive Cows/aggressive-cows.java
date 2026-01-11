class Solution {
    public boolean canWePlace(int distance, int []stalls, int k, int n){
        int lastCowAt = stalls[0];
        int cowPlaced = 1;
        
        for(int i=1; i<n; i++){
            if(stalls[i] - lastCowAt >= distance){
                cowPlaced++;
                lastCowAt = stalls[i];
            }
        }
        
        if(cowPlaced >= k){
            return true;
        }
        
        return false;
        
    }
    public int aggressiveCows(int[] stalls, int k) {
       
        int n = stalls.length;
        Arrays.sort(stalls);
        int ans = 0;
        
        int x = stalls[n-1] - stalls[0];
        
        int low = 1;
        int high = x;
        
        
        while(low <= high){
            int mid = low + (high-low)/2;
            
            if(canWePlace(mid,stalls,k,n)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid -1;
            }
        }
        
        // for(int i=0; i<=x; i++){
        //     if(canWePlace(i,stalls,k,n)){
        //         continue;
        //     }
        //     else{
        //         ans = i-1;
        //         break;
        //     }
        // }
        return ans;
    }
}