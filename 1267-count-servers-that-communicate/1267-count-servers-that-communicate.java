class Solution {
    public int countServers(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        
        int[] rowCount = new int[rows];
        int[] colCount = new int[cols];
        
        // Step 1: Har row aur column mein total servers count kar lo
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
        
        int communicatingServers = 0;
        
        // Step 2: Check karo ki kaunsa server communicate kar sakta hai
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    // Agar uski row ya column mein 1 se zyada server hain, toh wo communicate karega
                    if (rowCount[i] > 1 || colCount[j] > 1) {
                        communicatingServers++;
                    }
                }
            }
        }
        
        return communicatingServers;
    }
}