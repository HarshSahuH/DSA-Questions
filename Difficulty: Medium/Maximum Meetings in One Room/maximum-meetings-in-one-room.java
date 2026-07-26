class Solution {
    
    static class Meeting{
        int start;
        int finished;
        int index;
        
        Meeting(int start, int finished, int index){
            this.start = start;
            this.finished = finished;
            this.index = index;
        }
    }
    
    public ArrayList<Integer> maxMeetings(int[] s, int[] f) {
        // code here
        int n = s.length;
        ArrayList<Meeting> meetings = new ArrayList<>();
        
        //pack start finished 1 index together 
        for(int i=0; i<n ;i++){
            meetings.add(new Meeting(s[i], f[i], i+1));
        }
        
        meetings.sort( (a,b)-> {
            if(a.finished != b.finished){
                return Integer.compare(a.finished, b.finished);
            }
            return Integer.compare(a.index, b.index);
        });
        
        ArrayList<Integer> ans = new ArrayList<>();
        int lastOcupiedTime = -1;
        
        for(Meeting m : meetings){
            if(m.start > lastOcupiedTime){
                ans.add(m.index);
                lastOcupiedTime = m.finished; 
            }
        }
        
        Collections.sort(ans);
        return ans;
    }
}