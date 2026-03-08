class Solution {
    public void insert(int element, Stack<Integer> st){
        if(st.empty()){
            st.push(element);
        }
        else if(st.peek() <= element){
            st.push(element);
        }
        else{
          int top = st.peek();
          st.pop();
          insert(element,st);
          st.push(top);
        }
    }
    public void sortStack(Stack<Integer> st) {
        // code here
        if(st.size() == 1){
            return ;
        }
        if(st.empty()){
            return ;
        }
        int top = st.peek();
        st.pop();
        
        sortStack(st);
        insert(top,st);
    }
}