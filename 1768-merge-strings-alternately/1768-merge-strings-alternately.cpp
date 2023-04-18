class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        
        string result="";
        int i=0,j=0;
        int word1Len = word1.length();
        int word2Len = word2.length();
        
        
        while(i<word1Len && j<word2Len ){
            result.push_back(word1[i++]);
            result.push_back(word2[j++]);
        }
        
        while(i<word1Len){
            result.push_back(word1[i++]);
        }
        
        while(j<word2Len){
           result.push_back(word2[j++]);
        }
        
        
        return result;
    }
};