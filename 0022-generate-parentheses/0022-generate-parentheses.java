class Solution {
        public void helper(int n,List<String> ans, StringBuilder s,int numOfOpen, int numofClose){

        if(s.length() == 2*n){
            ans.add(s.toString());
            return ;
        }
        
        if(numOfOpen < n){
            s.append('(');
            helper(n,ans,s,numOfOpen+1,numofClose);
            s.deleteCharAt(s.length()-1);
        }
        if(numofClose < numOfOpen){
            s.append(')');
            helper(n,ans,s,numOfOpen,numofClose+1);
            s.deleteCharAt(s.length()-1);
        }

    }
    public List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList<>();
        StringBuilder s = new StringBuilder();
        helper(n,ans,s,0,0);
        return ans;
    }
}