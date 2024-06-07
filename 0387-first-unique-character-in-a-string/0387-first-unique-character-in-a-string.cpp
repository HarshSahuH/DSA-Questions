class Solution {
public:
    int firstUniqChar(string s) {
        
        unordered_map<char,int> M;
        
        for(auto x : s){
            M[x]++;
        }
        
        for(int i = 0; i<s.size(); i++){
            if(M[s[i]] == 1){
                return i;
            }
        }
        
        return -1;
    }
};