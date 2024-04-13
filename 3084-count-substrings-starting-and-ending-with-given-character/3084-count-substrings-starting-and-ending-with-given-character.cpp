class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long charCount = 0;
        
        for(auto x : s){
            if(x == c){
                charCount++;
            }
        }
       
        return (charCount * (charCount + 1)) / 2;
    }
};