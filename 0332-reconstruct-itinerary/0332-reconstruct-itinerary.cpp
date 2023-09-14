class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>> adjList ;
        vector<string> result; //create a vector of string to store the order of path
        int n=tickets.size();

        for(int i=0;i<n;i++){
            adjList[tickets[i][0]].insert(tickets[i][1]);
        }

        stack<string> S; //creating stack for storing the result
        S.push("JFK");  //JFK is fixed staring point
            
        while(!S.empty())
        {
            string src = S.top();
            if(adjList[src].size()==0)
            {
                result.push_back(src);
                S.pop();
            }

            else
            {
                auto dst = adjList[src].begin();
                S.push(*dst);
                adjList[src].erase(dst);
            }
        }
        
        reverse(result.begin(),result.end());
        return result;
    }
};