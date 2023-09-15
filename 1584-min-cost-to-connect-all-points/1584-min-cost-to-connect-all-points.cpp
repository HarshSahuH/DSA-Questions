class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& p) {
        int n=p.size();
        vector<int> distance(n,1e9),visit(n);
        int ans=0;
        distance[0]=0;
        visit[0]=1;
        int k=n-1;
        int j=0;
        while(k--){
            int mini=1e9,mini_i;
            for(int i=0;i<n;i++){
                distance[i]=min(distance[i],abs(p[j][0]-p[i][0])+abs(p[j][1]-p[i][1]));
                if(!visit[i] && mini>distance[i]){
                    mini=distance[i];
                    mini_i=i;
                }
            }
            visit[mini_i]=1;
            ans+=distance[mini_i];
            j=mini_i;
        }
        return ans;
    }
};