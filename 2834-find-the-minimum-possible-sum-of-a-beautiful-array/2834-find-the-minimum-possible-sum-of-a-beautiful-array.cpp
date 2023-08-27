class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        long long ans = 0;
        set<int> S;
        
        for(int i=1; S.size() <n; i++){
            if(S.find(target - i) == S.end()){
                S.insert(i);
                ans += i;
            }
        }

        return ans;
    }
};