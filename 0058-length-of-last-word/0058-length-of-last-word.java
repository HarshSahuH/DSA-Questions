class Solution {
    public int lengthOfLastWord(String s) {
        int n = s.length();
        int lengthOfLastWord = 0;

        if (s.charAt(n - 1) == ' ') {
            while (s.charAt(n - 1) == ' ') {
                n--;
            }
        }

        while (n>0 && s.charAt(n - 1) != ' ') {
            lengthOfLastWord++;
            n--;
        }

        return lengthOfLastWord;
    }
}