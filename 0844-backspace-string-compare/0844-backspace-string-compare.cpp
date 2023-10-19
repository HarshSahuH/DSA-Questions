class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string tempS;
        string tempT;
        for (auto chr : s){
            if (chr == '#'){
                if (!tempS.empty())
                    tempS.pop_back();
            }
            else
                tempS.push_back(chr);
        }

        for (auto chr : t){
            if (chr == '#'){
                if (!tempT.empty())
                    tempT.pop_back();
            }
            else
                tempT.push_back(chr);
        }

        return tempS == tempT;
    }
};