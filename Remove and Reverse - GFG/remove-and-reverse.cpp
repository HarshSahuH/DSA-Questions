//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string S) {
 
      
       // Create a map to store the count of each character in the string
    unordered_map<char, int> charCount;
    for(int i=0; i<S.length(); i++) {
        charCount[S[i]]++;
    }

    // Create a string builder from the input string
    string sb = S;

    // Use two pointers to remove duplicates
    bool forward = true;
    int left = 0;
    int right = sb.length() - 1;
    while(left <= right) {
        if(forward) {
            // If the character at the left pointer has a count greater than 1, remove it
            if(charCount[sb[left]] > 1) {
                charCount[sb[left]]--;
                sb.erase(left, 1);
                right--;
                forward = !forward; // switch direction of pointer movement
            } else {
                left++; // move left pointer forward
            }
        } else {
            // If the character at the right pointer has a count greater than 1, remove it
            if(charCount[sb[right]] > 1) {
                charCount[sb[right]]--;
                sb.erase(right, 1);
                forward = !forward; // switch direction of pointer movement
            }
            right--; // move right pointer backward
        }
    }

    // If the pointers ended up crossing, the resulting string needs to be reversed
    return forward ? sb : string(sb.rbegin(), sb.rend());

    }
};





/*class Solution {
  public:
    string removeReverse(string S) {
       
       string ans = S;
       map<char,int> m; 
       
       for(int i=0; i<ans.size(); i++){
           char ch = ans[i];
           
           if(m.find(ch) != m.end()){
               char repeatedCh = ch;
               int index = m[repeatedCh];
               ans.erase(index,1);
               reverse(ans.begin(),ans.end());
               m.clear();
               for(int j=0; j<ans.size(); j++){
                   m.insert({ans[j],j});
               }
               i=-1;
           }
           else{
               m.insert({ch,i});
           }
           
       }
       
       return ans;
    }
};*/


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends