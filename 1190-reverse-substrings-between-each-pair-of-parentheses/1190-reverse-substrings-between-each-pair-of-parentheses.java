class Solution {
   
    public String reverseParentheses(String s) {
        Stack<Character> stk = new Stack<>();
        StringBuilder ans = new StringBuilder(); 

        int n = s.length();

        for(int i=0; i<n; i++){
            if(s.charAt(i) != ')'){
                stk.push(s.charAt(i));
            }else{
                StringBuilder temp = new StringBuilder();
                while(stk.peek() != '('){
                    temp.append(stk.peek());
                    stk.pop();
                }
                stk.pop(); // just to remove the brace of   (love

                for(int j=0; j<temp.length(); j++){
                    stk.push(temp.charAt(j));
                } 
            }
        }

        while(!stk.isEmpty()){
            ans.append(stk.peek());
            stk.pop();
        }

        return ans.reverse().toString(); 
    }
}