//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
       if(s1.length()!=s2.length()) return false;
       
       
       string s1s1 = s1+s1;
       
      auto isFound = s1s1.find(s2);  //find()Position of the first character of the found
                                     //substring or npos if no such substring is found.
                                     //cout<<isFound<<endl;
       
       if(isFound != string::npos){
           return true;
       }
       else {
           return false;
       }
    }
};

/*
  std::string str = "world, hello!";
  std::size_t pos = str.find("hello");
  
  if (pos != std::string::npos) {
    std::cout << "Substring found at position " << pos << std::endl;
   } 
   else {
    std::cout << "Substring not found." << std::endl;
    }

If the substring "hello" is found in the string, the find()
function will return the index of the first character of the substring 
in the string (in this case, pos will be equal to 7). If the substring
is not found, the function will return string::npos, which is a special
value indicating that the substring was not found in the string. In this
case, the code will output "Substring not found.".*/


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}

// } Driver Code Ends