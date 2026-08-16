class Solution {
   
    public int[][] insert(int[][] intervals, int[] newInterval) {
       int i=0; 
       while(i < intervals.length){
        // Case 1: Current interval ends before newInterval starts (No overlap)
        if(intervals[i][1] < newInterval[0]){
            i++;
        }
        // Case 2: Current interval starts after newInterval ends (No overlap, insert position found)
        else if ( intervals[i][0] > newInterval[1]){
            return insertAt(intervals,newInterval,i);
        }
        else{
            // Case 3: Overlapping intervals -> Merge into newInterval and erase current interval
            newInterval[0] = Math.min(intervals[i][0], newInterval[0]);
            newInterval[1] = Math.max(intervals[i][1], newInterval[1]);
            intervals = earseAt(intervals,newInterval,i);
        }
       }

       return insertAt(intervals, newInterval, intervals.length);
    }


    public int[][] insertAt(int[][] intervals, int[] value,int pos){
        int[][] res =  new int[intervals.length+1][2];

        for(int i=0; i<pos; i++){
            res[i] = intervals[i];
        } 
        res[pos] = value; 

        for(int i = pos; i<intervals.length; i++){
            res[i+1] = intervals[i];
        }
        return res;
    }

    public int[][] earseAt(int[][] intervals, int[] value,int pos){
        int[][] res =  new int[intervals.length-1][2];

        for(int i=0; i<pos; i++){
            res[i] = intervals[i];
        }
        for(int i=pos+1; i<intervals.length; i++){
            res[i-1] = intervals[i];
        }
        return res;
    }
}