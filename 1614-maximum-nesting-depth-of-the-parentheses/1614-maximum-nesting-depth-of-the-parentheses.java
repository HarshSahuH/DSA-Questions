class Solution {
    public int maxDepth(String s) {
        int maxDept = Integer.MIN_VALUE; 
        int NoLeftBraceBefore = 0;
        int NoRigthBraceBefore = 0;
        
        for(int i=0; i<s.length(); i++){
            if(s.charAt(i) == '('){
                NoLeftBraceBefore++;
            }
            if(s.charAt(i) == ')'){
                NoRigthBraceBefore++;
            }

            int currDept = NoLeftBraceBefore - NoRigthBraceBefore;
            maxDept = Math.max(maxDept,currDept);
        }
        return maxDept;
    }
}