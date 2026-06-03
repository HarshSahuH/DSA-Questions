class Solution {
    public int leastInterval(char[] tasks, int n) {
        int[] charArr = new int[26];
        PriorityQueue<Integer> mxHp = new PriorityQueue<>(Collections.reverseOrder());
        int time = 0;
        for(char ch : tasks){
            charArr[ch-'A']++;
        }

        for(int x : charArr){
            if(x>0){
                mxHp.add(x);
            }
        }

        while(!mxHp.isEmpty()){
            ArrayList<Integer> temp = new ArrayList<>();
            for(int i=1; i<=n+1; i++){
                if(mxHp.size() != 0){
                    int freq = mxHp.poll();
                    freq--;
                    temp.add(freq);
                }
            }
            for(int x : temp){
                if(x>0){
                    mxHp.add(x);
                }
            }
            if(mxHp.isEmpty()){
                time += temp.size();
            }
            else{
                time += n+1;
            }
        }
        return time;
    }
}