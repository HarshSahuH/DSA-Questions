class Solution {
public:
    bool find132pattern(vector<int>& nums) {
    int i, n = nums.size(), second_mx = INT_MIN;
    stack<int> st;
        
        for (i=n-1;i>=0;i--) {
            if (nums[i] < second_mx) return 1;
                while (st.size() && st.top() < nums[i]) {
                    second_mx = max(second_mx, st.top());
                    st.pop();
                }
                      st.push(nums[i]);
        }
    return 0;
    }
};

/*
  T.C. : O(N) Since we traverse all the elements once
  S.C. : O(N) Since stack as extra space is used.
*/