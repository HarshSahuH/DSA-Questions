class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<int> s1,t1;
        string tempS = "";
        string tempT = "";
        
        for(int i=0; i<s.size(); i++){
            if(s[i] == '#' && !s1.empty())
                s1.pop();
            
            else if(s[i] != '#')
                s1.push(s[i]);
            
        }
        
       for(int i=0; i<t.size(); i++){
            if(t[i] == '#' && !t1.empty())
                t1.pop();
            
            else if(t[i] != '#')
                t1.push(t[i]);
            
        }
        
        while(!s1.empty()){
            tempS.push_back(s1.top());
            s1.pop();
        }
        
         while(!t1.empty()){
            tempT.push_back(t1.top());
            t1.pop();
        }
        return tempS == tempT;
    }
};