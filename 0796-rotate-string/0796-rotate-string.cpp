class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;
        
        if (s.empty()) return true;  // Both strings are empty, consider it as a rotation
        
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == goal[0]) {
                int j = 0;
                while (j < n && s[(i + j) % n] == goal[j]) {
                    j++;
                }
                
                if (j == n) return true;  // Found a rotation
            }
        }
        
        return false;  // No rotation found
    }
};

//T.C. O(N) s.c. O(1)