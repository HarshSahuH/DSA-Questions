class Solution {
public:
    bool isPalindrome(string s) {
      if(s.length() ==0 || s.length() == 1){
        return true;          
      }    
        
        int st = 0;
        int en = s.length()-1;
        
        while(st < en){
            
            while( (st < en) && (!isalnum(s[st]) ) ) st++;
            
            while( (st < en) && !isalnum(s[en]) ) en--;
                
            if( (st < en) && (tolower(s[st]) != tolower(s[en]) ) )
                return false;
            else{
                st++;
                en--;
            }
        }
        return true;
    }
};

/*
T.C. O(N)
S.C. O(1)
*/