class Solution {
public:
    string countAndSay(int n) {
        
        string ans="1";
        int cnt = 0;
        for(int i=2; i<=n; i++)
        {
            string temp="";
            int cnt = 1; 
            for(int j=0; j<ans.size(); j++)
            {
                if(j < ans.size() - 1 && ans[j] == ans[j+1])
                {
                    cnt++;
                }
                else
                {
                   temp +=(cnt+'0');
                   temp +=ans[j];
                   cnt = 1;
                }
            }
            ans = temp;      
        }

        return ans;
    }
};