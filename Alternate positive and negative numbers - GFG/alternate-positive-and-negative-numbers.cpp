//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	   
	  vector<int> pos_Elmnt;
        vector<int> neg_Elmnt;

        for (int i = 0; i < n; i++) {
            if (arr[i] < 0)
                neg_Elmnt.push_back(arr[i]);
            else
                pos_Elmnt.push_back(arr[i]);
        }

        int i = 0, nn = 0, p = 0;
        while (i < n && p < pos_Elmnt.size() && nn < neg_Elmnt.size()) {
            arr[i++] = pos_Elmnt[p++];
            arr[i++] = neg_Elmnt[nn++];
        }

        while (i < n && p < pos_Elmnt.size()) {
            arr[i++] = pos_Elmnt[p++];
        }

        while (i < n && nn < neg_Elmnt.size()) {
            arr[i++] = neg_Elmnt[nn++];
        }
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends