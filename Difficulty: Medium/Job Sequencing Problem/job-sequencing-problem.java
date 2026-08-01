import java.util.*;

class Solution {

    static class Job {
        int deadline;
        int profit;

        Job(int deadline, int profit) {
            this.deadline = deadline;
            this.profit = profit;
        }
    }

    // DSU Find Function with Path Compression
    private int find(int i, int[] parent) {
        if (i == parent[i]) {
            return i;
        }
        return parent[i] = find(parent[i], parent); // Path Compression
    }

    public ArrayList<Integer> jobSequencing(int[] deadline, int[] profit) {
        int n = deadline.length;
        ArrayList<Job> jobs = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            jobs.add(new Job(deadline[i], profit[i]));
        }

        // 1. Sort jobs by profit in DECREASING order
        jobs.sort((a, b) -> Integer.compare(b.profit, a.profit));

        // 2. Find max deadline to initialize DSU parent array
        int maxDeadline = 0;
        for (int d : deadline) {
            maxDeadline = Math.max(maxDeadline, d);
        }

        // parent array of size maxDeadline + 1
        int[] parent = new int[maxDeadline + 1];
        for (int i = 0; i <= maxDeadline; i++) {
            parent[i] = i; // Initially, every slot points to itself
        }

        int countJobs = 0;
        int totalProfit = 0;

        // 3. Process jobs using DSU
        for (Job job : jobs) {
            // Cap the deadline if it exceeds maxDeadline
            int cappedDeadline = Math.min(maxDeadline, job.deadline);
            
            // Direct O(1) jump to the latest available free slot
            int availableSlot = find(cappedDeadline, parent);

            if (availableSlot > 0) {
                // Free slot mil gaya!
                countJobs++;
                totalProfit += job.profit;

                // Is slot ko occupy kar liya, ab next time piche waala slot check hoga
                parent[availableSlot] = find(availableSlot - 1, parent);
            }
        }

        ArrayList<Integer> ans = new ArrayList<>();
        ans.add(countJobs);
        ans.add(totalProfit);

        return ans;
    }
}