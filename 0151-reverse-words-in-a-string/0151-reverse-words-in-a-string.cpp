class Solution {
public:
    string reverseWords(string s) {
        
        string ans = "";
        stack<string> stk;
        int n = s.length();
        
        int i=0;
        while(i<n)
        {
            if(s[i] == ' ')
            {
                i++;
                continue;
            }
            
            else
            {
             string temp = "";
             while(i<n && s[i] != ' ')
             {
                temp = temp + s[i];
                i++;
             }
             stk.push(temp);
            }
        }
        
        while(!stk.empty())
        {
           ans = ans + stk.top()+" ";
          stk.pop();
        }
        
        //revome the last space 
        if(!ans.empty())
        {
            ans.pop_back();
        }
        return ans;
    }
};