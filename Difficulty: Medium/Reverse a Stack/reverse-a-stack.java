class Solution {
    public static void insert(Stack<Integer> st, int element){
        if(st.empty()){
            st.push(element);
            return ;
        }
        
        int peak = st.pop();
        
        insert(st,element);
        
        st.push(peak);
        
    }
    public static void reverseStack(Stack<Integer> st) {
        // code here
        if(st.size()==1){
            return ;
        }
        int element = st.pop();// Removes the top value AND returns it to 'element'
        
        reverseStack(st);
        
        insert(st,element);
    }
}
