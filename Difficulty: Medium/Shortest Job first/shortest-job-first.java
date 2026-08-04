class Solution {
    static int solve(int bt[]) {
        int n = bt.length;
        
        if(n == 1){
            return 0;
        }
        
        int waitingTimeForNextJob = 0;
        int[] forExecutingJobWaitingTime = new int[n];
        
        Arrays.sort(bt);
        
        for(int i=0; i<n; i++){
            forExecutingJobWaitingTime[i] = waitingTimeForNextJob;
            waitingTimeForNextJob += bt[i];
        }
        
        long sum = 0; 
        for(int i= 0; i<n; i++){
            sum += forExecutingJobWaitingTime[i];
        }
        
        return (int)sum/n;
        
    }
}
