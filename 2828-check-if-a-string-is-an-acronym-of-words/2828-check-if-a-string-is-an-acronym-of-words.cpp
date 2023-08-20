class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        
        
        string temp = "";
        
        for(auto w: words)
            temp = temp + w[0];
        
        return temp == s ;
    }
};