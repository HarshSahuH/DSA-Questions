// User function Template for Java

class Solution {
    public void helper(List<String> ans, String s, int index, String curr){
        if(index == s.length()){
            if(curr.length()>0){//to avoid empty string 
                ans.add(curr); 
            } 
            return ;
        }
        // include the character
        helper(ans, s, index + 1, curr + s.charAt(index));
        
        // exclude the character
        helper(ans, s, index + 1, curr);
        
    }
    
    public List<String> AllPossibleStrings(String s) {
        // Code here
        List<String> ans = new ArrayList<>();
        helper(ans,s,0,"");
        
        Collections.sort(ans);
        return ans;
    }
}