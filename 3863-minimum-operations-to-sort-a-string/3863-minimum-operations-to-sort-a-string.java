class Solution {
    public int minOperations(String s) {
        int n = s.length();
        
        // 0 operations if already sorted
        boolean sorted = true;
        for (int i = 0; i < n - 1; i++) {
            if (s.charAt(i) > s.charAt(i + 1)) {
                sorted = false;
                break;
            }
        }
        if (sorted) return 0;
        
        // Find min and max characters
        char mn = s.charAt(0);
        char mx = s.charAt(0);
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            if (c < mn) mn = c;
            if (c > mx) mx = c;
        }
        
        // 1 operation check
        if (s.charAt(0) == mn || s.charAt(n - 1) == mx) {
    return 1;
}
        
        // If impossible to sort (like "gf" or strings where elements are strictly decreasing with no escape)
        // Check if we can form it in 2 or 3 operations:
        // Hint 4: Check if 'mn' appears in any proper prefix (0 to n-2) OR 'mx' in any proper suffix (1 to n-1)
        boolean hasMnInPrefix = false;
        boolean hasMxInSuffix = false;
        
        for (int i = 0; i < n - 1; i++) {
            if (s.charAt(i) == mn) hasMnInPrefix = true;
        }
        for (int i = 1; i < n; i++) {
            if (s.charAt(i) == mx) hasMxInSuffix = true;
        }
        
        if (!hasMnInPrefix && !hasMxInSuffix) {
            // For a 2-character string like "gf", it hits here and should return -1 if it can't be sorted.
            // Wait, for "gf", can we do it? Let's check if it's strictly decreasing of length 2.
            if (n == 2) return -1;
            return 3;
        }
        
        return 2;
    }
}