class Solution {
    public int[][] merge(int[][] intervals) {
        int n = intervals.length;
        List<int[]> ans = new ArrayList<>();
        Arrays.sort(intervals, (a,b)->Integer.compare(a[0],b[0]));

        ans.add(intervals[0]);

        int i = 1;
        while(i<=n-1){
            //current interval is not at all Overlaping with the next interval
            int[] lastInterval = ans.get(ans.size()-1);

            if(intervals[i][0] > lastInterval[1]){
                ans.add(intervals[i]);
            }
            //current interval is overlapping with the next interval
            else{
                lastInterval[1] = Math.max(intervals[i][1], lastInterval[1]);
                ans.remove(ans.size()-1);
                ans.add(lastInterval);
            }
            i++;
        }
        return ans.toArray(new int[ans.size()][]);
    }
}