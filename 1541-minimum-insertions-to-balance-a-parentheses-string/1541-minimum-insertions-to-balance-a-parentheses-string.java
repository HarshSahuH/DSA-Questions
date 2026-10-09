class Solution {
    public int minInsertions(String s) {
        int n = s.length();
        int need = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '(') {
                if (need % 2 != 0) {
                    ans++;
                    need--;
                }
                need += 2;
            } else {
                need--;
                if(need < 0){
                    ans++;
                    need = 1;
                }
            }

        }

        return ans + need;
    }
}