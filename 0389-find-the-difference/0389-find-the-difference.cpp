class Solution {
public:
    char findTheDifference(string s, string t) {
        int sumofAsciiS = 0;
        int sumofAsciiT = 0;
        
        for(char c : s) sumofAsciiS += c;
        for(char c : t) sumofAsciiT += c;
        
        return sumofAsciiT - sumofAsciiS;
    }
};