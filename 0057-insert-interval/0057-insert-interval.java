class Solution {
   
    public int[][] insert(int[][] intervals, int[] newInterval) {

       List<int[]> ans = new ArrayList<>(); 
       int i=0;
       int n = intervals.length;

       while(i < n){
            // Case 1: Current interval ends before newInterval starts (No overlap)
            if(intervals[i][1] < newInterval[0]){
                ans.add(intervals[i]);
            }
            // Case 2: Current interval starts after newInterval ends (No overlap, insert position found)
            else if ( intervals[i][0] > newInterval[1]){
                break;
            }
            else{
                // Case 3: Overlapping intervals -> Merge into newInterval and erase current interval
                newInterval[0] = Math.min(intervals[i][0], newInterval[0]);
                newInterval[1] = Math.max(intervals[i][1], newInterval[1]);
            }
            i++;
       }
       ans.add(newInterval);
       //Add all remaining intervals that start AFTER newInterval ends 
       while(i<intervals.length){
        ans.add(intervals[i]);
        i++;
       }
        
       return ans.toArray( new int[ans.size()][]);
    }
}