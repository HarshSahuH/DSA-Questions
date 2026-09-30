class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        int n = seq.length();
        int[] result = new int[n];
        int dept=0;

        for(int i=0; i<n; i++){
            if(seq.charAt(i) =='('){
                dept++;
                result[i] = dept%2 ==0 ? 0 : 1;
            }else if(seq.charAt(i) == ')'){
                 result[i] = dept%2 ==0 ? 0 : 1;
                 dept--;
            }
        }
        return result;
    }
}