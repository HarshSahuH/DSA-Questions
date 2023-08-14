class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> mnHeap;
        
        for (int num: nums)
        {
            mnHeap.push(num);
            if (mnHeap.size() > k){
                mnHeap.pop();
            }
        }
        
        return mnHeap.top();
    }
};
