class Solution {
public:
    int maxDepth(string s) {
        
        int depth = 0, O_P = 0; 
        
        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            
            if(ch =='(')
                O_P++;
            
            if(ch==')')
                O_P--;
            
            depth = max(depth,O_P);
        }
        
        return depth;
    }
};