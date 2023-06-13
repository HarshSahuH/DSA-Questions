class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        char *arr = new char[s.length()];
        
        for(int i=0; i<s.length(); i++){
            arr[indices[i]] = s[i];
        }
        
        string res(arr,s.length());
        delete[] arr;
        return res;
    }
};

/*
T.C. O(N) 
S.C. O(N)
*/


//method 2 efficient but same T.C. O(N) and S.C. O(N)
/*
#include <string>
#include <vector>

class Solution {
public:
    std::string restoreString(std::string s, std::vector<int>& indices) {
        std::string res(s.length(), ' ');
        
        for (int i = 0; i < s.length(); i++) {
            res[indices[i]] = s[i];
        }
        
        return res;
    }
};
*/