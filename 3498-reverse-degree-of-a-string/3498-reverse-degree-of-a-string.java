class Solution {
    public int reverseDegree(String s) {
        int arr[] = new int[26];
        int ans = 0; 

        int start = 26;
        for(int i=0; i<=25; i++){
            arr[i] = start;
            start--;
        }
        
        for(int i=0; i<s.length(); i++){
            char ch = s.charAt(i);
            ans += (arr[ch - 'a'] * (i+1));
        }

        return ans;
    }
}