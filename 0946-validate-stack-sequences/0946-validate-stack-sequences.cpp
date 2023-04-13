class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        stack<int> s;
        
        for(int i=0,j=0; i<pushed.size(); i++){
            s.push(pushed[i]);
            
            while(!s.empty() && s.top() == popped[j]){
                s.pop();
                j++;
            }
            
        }
        
        // if(s.size()==0){
        //     return true;
        // }
        // else{
        //     return false;   
        // }
        //we can reduse the above code line by single line 
        return s.empty();
        
        //T.C => O(n*m) where n=size of pushed array ans m is size of poped array
        //S.C => O(n) because we push all element in worst case 
        
    }
};