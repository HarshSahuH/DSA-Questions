class Solution {
public:
    string reorganizeString(string s) {
        
        string ans ="";
        vector<int> charCounts(26,0);
        for(char x:s)
        {
            charCounts[x-'a']++; 
        }
        
        priority_queue<vector<int>> pq;
        for(int i=0; i<26; i++)
        {
            if(charCounts[i] >0)
            {
                pq.push(vector<int>{charCounts[i],i+'a'});
            }
        }
        
        while(!pq.empty())
        {
            auto first = pq.top();
            pq.pop();
            if(ans.empty() || first[1] != ans.back())
            {
                ans = ans + char(first[1]);
                if(--first[0] > 0)
                pq.push(first);
            }
            else
            {
                if(pq.empty())
                    return "";
                auto second = pq.top();
                pq.pop();
                ans = ans + char(second[1]);
                if(--second[0] > 0)
                {
                    pq.push(second);
                }
                pq.push(first);
            }
            
        }
        return ans;
    }
};