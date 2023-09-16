class Solution {
    vector<int> DIR = {0, 1, 0, -1, 0};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        // Initialize a 2D array to store distances with max values.
        std::vector<std::vector<int>> dist(m, std::vector<int>(n, INT_MAX));
        
        // Create a min-heap to store distance, row, and column values.
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, std::greater<std::vector<int>>> minHeap;
        
        // Initialize the min heap with starting point (distance, row, col).
        minHeap.push({0, 0, 0});
        
        // Set the distance to the starting point as 0.
        dist[0][0] = 0;
        
        while (!minHeap.empty()) {
            std::vector<int> top = minHeap.top();
            minHeap.pop();
            
            int d = top[0];
            int r = top[1];
            int c = top[2];
            
            // If this is an outdated version, skip it.
            if (d > dist[r][c]) continue;
            
            // If we reach the bottom right, return the distance.
            if (r == m - 1 && c == n - 1) return d;
            
            // Explore neighboring cells.
            for (int i = 0; i < 4; i++) {
                int nr = r + DIR[i];
                int nc = c + DIR[i + 1];
                
                // Check if the neighbor is within bounds.
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    // Calculate the new distance.
                    int newDist = std::max(d, std::abs(heights[nr][nc] - heights[r][c]));
                    
                    // If the new distance is smaller, update the distance and add to the heap.
                    if (dist[nr][nc] > newDist) {
                        dist[nr][nc] = newDist;
                        minHeap.push({dist[nr][nc], nr, nc});
                    }
                }
            }
        }
        
        return 0;
    }
};