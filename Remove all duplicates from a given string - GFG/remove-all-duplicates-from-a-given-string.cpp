//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	    unordered_map<int,int> m;
	    int j=0;
	    for(int i=0;i<str.length();i++){
	        if(m[str[i]]==0){
	            str[j++] = str[i];
	            m[str[i]]++;
	        }
	    }
	    return str.substr(0,j);

	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends