class Solution {
    bool isPalindrome(string str){
            int j=0, k=str.length()-1;
            while(j<=k){
                if(str[j]==str[k]){
                  j++;
                  k--;  
                }
                else{
                    return false;
                }
            }
        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        
        string first="";
        
        for(int i = 0; i < words.size(); i++){
            if(isPalindrome(words[i])==1){
                return words[i];
            }
        }
        return first;
    }
};