class Solution {
public:
    int minDeletions(string s) {
        int deletion = 0;
   
        vector<int> freqArr(26);
        for(auto c : s){
            freqArr[c-'a']++;
        }
        
        //all the unique frequency that is exist in the input string 
        set<int> uniqueFrequency;
        for(int count : freqArr){
            while(count > 0 && uniqueFrequency.find(count) != uniqueFrequency.end()){
                deletion++;
                count--;   
            }
            uniqueFrequency.insert(count);
        }
        return deletion;
    }
};


//Time Complexity: O(n)
//Space Complexity: O(n)
//https://www.youtube.com/watch?v=NEkK2SuWxI8
