class Solution {
public:
    int longestValidParentheses(string s) {
        
        stack<char> ch;
        stack<int>index;
        index.push(-1);
        
        int len = 0;
        
        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){ //opening at s[i]
                ch.push(s[i]);
                index.push(i);
            }
            else{  //closing at s[i]
                if(!ch.empty() && ch.top()=='('){
                    ch.pop();
                    index.pop();
                    len = max(len,i-index.top());
                }
                else{
                    index.push(i);
                }
            }
        }
            return len;
    }
};