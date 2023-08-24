//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    static bool cmp(pair<int,int> a, pair<int, int> b){
        return a.second < b.second;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> timing;
        
        for(int i=0; i<n; i++){
            pair<int,int> p = {start[i],end[i]};
            timing.push_back(p);
        }
        
        //sort on the basis of ending time of meeting, in increasing order like 2 4 6 7 9 9 
        sort(timing.begin(),timing.end(),cmp);
        
        int meetingHeld = 1;
        int meetingHeld_start_time = timing[0].first;
        int meetingHeld_end_time = timing[0].second;
        
        for(int i=1; i<n; i++){
            int currStarting = timing[i].first;
            if(currStarting > meetingHeld_end_time){
                meetingHeld++;
                meetingHeld_end_time = timing[i].second;
            }
        }
      return meetingHeld;  
    }
};
//T.C. O(N) + O(NlogN) + O(N) = O(NlogN) 
//S.C. O(N) 


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends