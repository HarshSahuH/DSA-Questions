class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()){
            return false;
        }
        
        string twiceS = s + s;
        
        if(twiceS.find(goal) != -1){
            return true;
        }
        return false;
    }
};