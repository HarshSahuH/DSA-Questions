class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_set<int> notRequired;
        int ans = 0;
        
        for(int i=1; notRequired.size() < n; i++){
            
            if(notRequired.find(k-i) == notRequired.end()){
                 notRequired.insert(i);
                 ans += i;
            }
            
                      
        }
        return ans;
    }
};