class Solution {
public:
    bool isValid(string s) {
        
        int n = s.length();
        if(n==1) return false;
        
        stack<char> stk;
        
        for(int i=0; i<n; i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] =='[')
                stk.push(s[i]);
            else
            {
                if(stk.empty())
                    return false;
                char temp = stk.top();
                stk.pop();
                
                if(temp == '(' && s[i] == ')' || 
                   temp == '{' && s[i] == '}' || 
                   temp == '[' && s[i] == ']')
                    continue;
                else
                    return false;
            }   
        }
        if(stk.empty())
            return true;
        else 
            return false;
    }
};